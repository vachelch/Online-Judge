#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int x;
	int y;
	int val;
} *Heap;

int Father(int k){
	return (k+1)/2 - 1;
}
int Left(int k){
 	return k*2 + 1;
}
int Right(int k){
	return k*2 + 2;
}

void swap(Heap *min_heap, int k, int fa){
	Heap tmp = min_heap[k];
	min_heap[k] = min_heap[fa];
	min_heap[fa] = tmp;
}

void Min_heapify(Heap *min_heap, int heap_len, int k){
	int l = Left(k);
	int r = Right(k);

	int least = k;
	if(l < heap_len && min_heap[l]->val < min_heap[k]->val)
		least = l;
	if(r < heap_len && min_heap[r]->val < min_heap[least]->val)
		least = r;

	if(least != k){
		swap(min_heap, k, least);
		Min_heapify(min_heap, heap_len, least);
	}
}

void Float(Heap *min_heap, int k){
	int fa = Father(k);

	if (fa >= 0 && min_heap[k]->val < min_heap[fa]->val){
		swap(min_heap, k, fa);
		Float(min_heap, fa);
	}
}

void Insert(Heap *min_heap, int *heap_len, int x, int y, int val){
	Heap node = (Heap) malloc(sizeof(struct node));
	node->x = x;
	node->y = y;
	node->val = val;

	min_heap[(*heap_len)++] = node;
	Float(min_heap, (*heap_len) - 1);
}

Heap Pop(Heap *min_heap, int *heap_len){
	Heap node = min_heap[0];
	min_heap[0] = min_heap[--(*heap_len)];

	Min_heapify(min_heap, *heap_len, 0);

	return node;
}


int kthSmallest(int **matrix, int matrixRowSize, int matrixColSize, int k) {
	Heap min_heap[matrixRowSize * matrixColSize];
	int *visited = (int *)malloc(matrixRowSize * matrixColSize * sizeof(int));
	for(int i=0; i< matrixRowSize * matrixColSize; i++)
		visited[i] = 0;
	visited[0] = 1;

	Heap node = (Heap) malloc(sizeof(struct node));
	node->x = 0;
	node->y = 0;
	node->val = matrix[0][0];
	min_heap[0] = node;
	int heap_len = 1;

	int mink_val;
	while(k--){
		//debug
		// for(int i=0; i<heap_len; i++)
		// 	printf("%d ", min_heap[i]->val);
		// printf("\n");

		Heap node = Pop(min_heap, &heap_len);
		int x = node->x;
		int y = node->y;
		mink_val = node->val;

		if (x+1 < matrixRowSize && visited[(x+1)*matrixColSize + y] == 0){
			Insert(min_heap, &heap_len, x+1, y, matrix[x+1][y]);
			visited[(x+1)*matrixColSize + y] = 1;
		}
		if (y+1 < matrixColSize && visited[(x)*matrixColSize + y+1] == 0){
			Insert(min_heap, &heap_len, x, y+1, matrix[x][y+1]);
			visited[(x)*matrixColSize + y+1] = 1;
		}
	}

	return mink_val;
}

int main(){
	int matrixRowSize = 3; 
	int matrixColSize = 3; 
	int k = 6;
	int matrix[3][3] = {{1, 3, 5}, {6, 7, 12}, {11, 14, 14}};

	int mink_val = kthSmallest(matrix, matrixRowSize, matrixColSize, k);

	printf("%d\n", mink_val);

	return 0;
}






















