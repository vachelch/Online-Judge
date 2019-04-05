#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct node{
	int idx;
	double weight;
	struct node * next;
} *Node;

typedef struct list{
	int idx;
	int pi;
	double dis_fa;
	int color;
	Node next;
} *List;

typedef struct queue{
	int idx;
	struct queue *next;
} *Queue;



Queue createQueue(){
	Queue queue = (Queue) malloc(sizeof(struct queue));
	queue->next = NULL;

	return queue;
}

void EnQueue(Queue queue, int k){
	Queue node = (Queue)malloc(sizeof(struct queue));
	node->idx = k;

	node->next = queue->next;
	queue->next = node;
}

void EnQueue_adj(List list, int idx, double weight){
	Node node = (Node) malloc(sizeof(struct node));
	node->idx = idx;
	node->weight = weight;

	node->next = list->next;
	list->next = node;
}

int isEmpty(Queue queue){
	return queue->next == NULL;
}

int Pop(Queue queue){
	Queue node = queue->next;
	queue->next = node->next;
	return node->idx;
}



double* calcEquation(char ***equations, int equationsRowSize, int equationsColSize, double* values, int valuesSize, char ***queries, int queriesRowSize, int queriesColSize, int* returnSize) {
	List adj_list[128];
	for(int i=0; i< 128; i++){
		adj_list[i] = (List) malloc(sizeof(struct list));
		adj_list[i]->idx = i;
		adj_list[i]->next = NULL;
	}

    for(int i=0; i< equationsRowSize; i++){
    	EnQueue_adj(adj_list[equations[i][0][0]], equations[i][1][0], values[i]);
    	EnQueue_adj(adj_list[equations[i][1][0]], equations[i][0][0], 1 / values[i]);
    }
    double * res = (double *)malloc(queriesRowSize * sizeof(double));

    // //debug
    // for(int i='a'; i<'d'; i++){
    // 	printf("%c ", adj_list[i]->idx);
    // 	Node cur = adj_list[i]->next;
    // 	while(cur){
    // 		printf("%c ->", cur->idx);
    // 		cur = cur->next;
    // 	}
    // 	printf("\n");
    // }

    for(int i=0; i< queriesRowSize; i++){
    	for(int j=0; j< 128; j++){
    		adj_list[j]->color = 0;
    	}

    	int numerator = queries[i][0][0];
    	int denominator = queries[i][1][0];

    	Queue queue = createQueue();
    	EnQueue(queue, numerator);
    	int flag = 1;

    	while(!isEmpty(queue)){
    		int cur = Pop(queue);
			Node adj = adj_list[cur]->next;
			while(adj){
				if (adj->idx == denominator){
					double mul = 1.0;
					adj_list[denominator]->dis_fa = adj->weight;
					adj_list[denominator]->pi = cur;
					int tmp = denominator;
					while(tmp != numerator){
						mul *= adj_list[tmp]->dis_fa;
						tmp = adj_list[tmp]->pi;
					}
					res[i] = mul;
					flag = 0;
					queue->next = NULL;
					break;
				}
				else if (adj_list[adj->idx]->color == 0){
					adj_list[adj->idx]->dis_fa = adj->weight;
					adj_list[adj->idx]->pi = cur;
					adj_list[adj->idx]->color = 1;
					EnQueue(queue, adj->idx);
				}

				adj = adj->next;
			}
			adj_list[cur]->color = 2;
    	}

    	if (flag)
    		res[i] = -1.0;
    }

    *returnSize = queriesRowSize;
    return res;
}

int main(){
	char equations[2][2][2] = { {"a", "b"}, {"b", "c"} };
	int equationsRowSize = 2;
	int equationsColSize = 2;
	double values[2] = {2.0, 3.0};
	int valuesSize = 2;
	char queries[5][2][2] = { {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"} };
	int queriesRowSize = 5;
	int queriesColSize = 2;
	int returnSize;

	double *res = calcEquation(equations, equationsRowSize, equationsColSize, values, valuesSize, queries, queriesRowSize, queriesColSize, & returnSize);

	for(int i=0; i<queriesRowSize; i++)
		printf("%lf ", res[i]);
	printf("\n");

	return 0;
}












