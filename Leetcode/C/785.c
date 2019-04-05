#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	int idx;
	struct list * next;
} *List;

void EnQueue(List list, int idx){
	List node = (List) malloc(sizeof(struct list));
	node->idx = idx;

	node->next = list->next;
	list->next = node;
}

int DFS(List *adj_list, int i, int *visited, int *set, int set_val){
	visited[i] = 1;
	
	List cur = adj_list[i]->next;
	while(cur){
		// printf("%d %d %d\n", i, cur->idx, set_val);
		if (visited[cur->idx] && set[cur->idx] == set_val){
			return false;
		}
		if (visited[cur->idx] == 0){
			set[cur->idx] = (set_val == 0);
			int bipartite = DFS(adj_list, cur->idx, visited, set, set[cur->idx]);
			if (!bipartite)
				return false;
		}

		cur = cur->next;
	}

	return true;
}

bool isBipartite(int **graph, int graphRowSize, int *graphColSizes) {
	List adj_list[graphRowSize];
	int set[graphRowSize];
	int *visited = (int *) malloc(graphRowSize * sizeof(int));

	for(int i=0; i< graphRowSize; i++){
		adj_list[i] = (List) malloc(sizeof(struct list));
		adj_list[i]->next = NULL;

		visited[i] = 0;

		for(int j=0; j< graphColSizes[i]; j++)
			EnQueue(adj_list[i], graph[i][j]);
	}

	// //debug
	// for(int i=0; i<graphRowSize; i++){
	// 	List cur = adj_list[i]->next;
	// 	printf("%d ", i);
	// 	while(cur){
	// 		printf("%d->", cur->idx);
	// 		cur = cur->next;
	// 	}
	// 	printf("\n");
	// }



	for(int i=0; i<graphRowSize; i++){
		if (visited[i] == 0 && graphColSizes[i] > 0){
			set[i] = 0;
			int bipartite =  DFS(adj_list, i, visited, set, 0);
			if (!bipartite)
				return false;
		}
	}

	return true;
}


int main(){
	int graph[][2] = {{1,3}, {0,2}, {1,3}, {0,2}};
	// int graph[][3] = {{1,2,3}, {0,2}, {0,1,3}, {0,2}};
	// int graph[][3] = {{4},{},{4},{4},{0,2,3}};
	
	int graphRowSize = 4;
	// int graphColSizes[] = {1,0,1,1,3};
	int graphColSizes[] = {2,2,2,2};

	printf("%d\n", isBipartite(graph, graphRowSize, graphColSizes));

	return 0;
}
















