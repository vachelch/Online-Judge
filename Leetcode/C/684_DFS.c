/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int val;
	struct list * next;
} *List;

void EnQueue(List head, int k){
	List node = (List) malloc(sizeof(struct list));
	node->val = k;

	node->next = head->next;
	head->next = node;
}

int DFS(int *color, List *adjacent_list, int *pi, int k){
	color[k] = 1;
	List cur = adjacent_list[k]->next;
	while(cur){
		int adj_idx = cur->val;
		if (color[adj_idx] == 1 && pi[k] != adj_idx){
			return true;
		}
		else if (color[adj_idx] == 0){
			pi[adj_idx] = k;	
			return DFS(color, adjacent_list, pi, cur->val);
		}

		cur = cur->next;
	}
	color[k] = 2;

	return false;
}

int* findRedundantConnection(int edges[][2], int edgesRowSize, int edgesColSize, int* returnSize) {
	int * res = (int *) malloc(2 * sizeof(int));

	List adjacent_list[1001];
	for(int i=0; i< 1001; i++){
		adjacent_list[i] = (List) malloc(sizeof(struct list));
		adjacent_list[i]->next = NULL;
	}

	int color[1001] = {0};
	int pi[1001];


	for(int i=0; i< edgesRowSize; i++){
		for(int j=0; j<1001; j++){
			pi[j] = -1;
			color[j] = 0;
		}

		int a = edges[i][0];
		int b = edges[i][1];

		EnQueue(adjacent_list[a], b);
		EnQueue(adjacent_list[b], a);


		List cur = adjacent_list[a]->next;
		if(cur){
			int loop = DFS(color, adjacent_list, pi, cur->val);
			if (loop == true){
				res[0] = a;
				res[1] = b;
				(*returnSize) = 2;
				return res;
			}

			cur = cur->next;
		}
	}

    *returnSize = 0;
    return res;
}


int main(){
	// int edges[5][2] = {{1,2}, {1,3}, {2,3}};
	// int edges[5][2] = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
	int edges[5][2] = {{1,2},{2,3},{2,4},{4,5},{1,5}};
	int edgesRowSize = 5, edgesColSize = 2, returnSize;

	int *res = findRedundantConnection(edges, edgesRowSize, edgesColSize, &returnSize);
	for(int i=0; i< returnSize; i++)
		printf("%d ", res[i]);

	printf("\n");

	return 0;
}




