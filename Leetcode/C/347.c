#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct heap {
	int val;
	int count;
} *Heap;

int Left(int k){
	return 2*k + 1;
}

int Right(int k){
	return 2*k + 2;
}

int Father(int k){
	return (k+1)/2 - 1;
}

void swap(Heap *max_heap, int a, int b){
	Heap node = max_heap[a];
	max_heap[a] = max_heap[b];
	max_heap[b] = node;
}

void Max_heapify(Heap *max_heap, int heap_len, int k){
	int l = Left(k);
	int r = Right(k);

	int largest = k;
	if(l < heap_len && max_heap[k]->count < max_heap[l]->count)
		largest = l;
	if(r < heap_len && max_heap[r]->count > max_heap[largest]->count)
		largest = r;

	if (largest != k){
		swap(max_heap, largest, k);
		Max_heapify(max_heap, heap_len, largest);
	}
}

// void Float(Heap *max_heap, int heap_len, int k){
// 	int fa = Father(k);
// 	if (fa >= 0 && max_heap[k]->count > max_heap[fa]->count){
// 		swap(max_heap, k, fa);
// 		Float(max_heap, heap_len, fa);
// 	}
// }

// void Insert(Heap *max_heap, int *heap_len, Heap node){
// 	max_heap[*heap_len] = node;
// 	++ (*heap_len);
// 	Float(max_heap, *heap_len, (*heap_len) - 1);
// }

Heap Pop(Heap *max_heap, int *heap_len){
	Heap node = max_heap[0];
	swap(max_heap, 0, (*heap_len) - 1);
	-- (*heap_len);
	Max_heapify(max_heap, *heap_len, 0);

	return node;
}

typedef struct hash{
	int val;
	int cnt;
} Hash;

int double_hash(Hash *hash_table, int table_len, int value, int i){
	int hash_1 = value % table_len;
	int hash_2 = value % (table_len+1);
	int idx = (hash_1 + i * hash_2) % table_len;

	if (idx < 0)
		idx += table_len;

	return idx;
}

void Hash_func(Hash *hash_table, int table_len, int value){
	int i = 0;
	int idx;

	while(1){
		idx = double_hash(hash_table, table_len, value, i);
		if (hash_table[idx].cnt == 0){
			hash_table[idx].val = value;
			hash_table[idx].cnt = 1;
			break;
		}
		else if(hash_table[idx].val == value){
			hash_table[idx].cnt += 1;
			break;
		}
		else{
			++ i;
		}
	}

	// printf("hash idx %d, val %d, cnt %d\n", idx, hash_table[idx].val, hash_table[idx].cnt);
}


int* topKFrequent(int* nums, int numSize, int k, int* returnSize) {
	*returnSize = k;

	int table_len = 2000;
	Hash hash_table[table_len];

	for(int i=0; i<table_len; i++)
		hash_table[i].cnt = 0;

	for(int i=0; i< numSize; i++)
		Hash_func(hash_table, table_len, nums[i]);

	Heap max_heap[numSize];
	int heap_len = 0;
	for(int i=0; i< table_len; i++){
		if(hash_table[i].cnt != 0){
			Heap node = (Heap)malloc(sizeof(struct heap));
    		node->val = hash_table[i].val;
    		node->count = hash_table[i].cnt;
    		max_heap[heap_len++] =  node;
		}
	}

	for(int i= heap_len/2; i>=0; i--)
		Max_heapify(max_heap, heap_len, i);

    int *res = (int *) malloc(k * sizeof(int));
    for(int i=0; i < k; i++){
    	Heap node = Pop(max_heap, &heap_len);
    	res[i] = node->val;
    }

    return res;
}


int main(){
	// int nums[] = {1, 1, 1, 2, 2, 3};
	// int numSize = 6;
	// int k = 2;
	int nums[] = {-1, -1};
	int numSize = 2;
	int k = 1;
	int returnSize;

	int *res = topKFrequent(nums, numSize, k, &returnSize);

	for(int i=0; i< returnSize; i++)
		printf("%d ", res[i]);
	printf("\n");

	return 0;
}





