/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

void merge(int *set, int set_a, int set_b){
	if (set_a > set_b){
		set[set_a] = set_b;
	}
	else{
		set[set_b] = set_a;
	}
}

int findSet(int *set, int k){
	while(set[k] != -1)
		k = set[k];
	return k;
}

int* findRedundantConnection(int **edges, int edgesRowSize, int edgesColSize, int* returnSize) {
	int * res = (int *) malloc(2 * sizeof(int));
	int *set = (int *)(malloc(1001 * sizeof(int)));
	for(int i=0; i< 1001; i++)
		set[i] = -1;

    for(int i=0; i< edgesRowSize; i++){
    	int  a = edges[i][0];
    	int  b = edges[i][1];
    	int set_a = findSet(set, a);
    	int set_b = findSet(set, b);

    	if (set_a != set_b){
    		merge(set, set_a, set_b);
    	}
    	else{
    		*returnSize = 2;
    		res[0] = a;
    		res[1] = b;
    		return res;
    	}
    }

    *returnSize = 0;
    return res;
}


int main(){
	int edges[5][2] = {{1,2}, {1,3}, {2,3}};
	// int edges[5][2] = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
	int edgesRowSize = 3, edgesColSize = 2, returnSize;

	int *res = findRedundantConnection(edges, edgesRowSize, edgesColSize, &returnSize);
	for(int i=0; i< returnSize; i++)
		printf("%d ", res[i]);

	printf("\n");


	printf("\n");
}
















