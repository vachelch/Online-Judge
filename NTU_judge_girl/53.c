#include <stdio.h>
int a[9];
int num;

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void permutate(int a[], int index, int size){
	if(index == size-1){
		for(int j = 0; j< size; j++){
			printf("%d", a[j]);
			if(j < size-1) printf(" ");
			else printf("\n");
		}
	}
	else{
		for(int i= index; i< size; i++){
			swap(&a[i], &a[index]);
			permutate(a, index+1, size);
			swap(&a[i], &a[index]);
		}
	}
}

void sort(int *a, int size){
	for(int i = size-2; i>=0; i--)
		for(int j = 0; j<= i; j++){
			int tmp;
			if(a[j] > a[j+1]){
				tmp = a[j+1];
				a[j+1] = a[j];
				a[j] = tmp;
			}
		}
}

int main(){
	scanf("%d", &num);
	for(int i=0; i<num; i++)
		scanf("%d", &a[i]);

	sort(a, num);

	permutate(a, 0, num);
	return 0;
}