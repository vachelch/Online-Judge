#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 1000

int count_binary(long long num){
	int count = 0;
	for(int i=0; i<64; i++){
		count += num & 1;
		num = num >> 1;
	}
	return count;
}

int compare(const void *num1 , const void *num2){
	long long *ptr1 = (long long *)num1;
	long long *ptr2 = (long long *)num2;
	int one_sum_1 = count_binary(*ptr1);
	int one_sum_2 = count_binary(*ptr2);
	if(one_sum_1 > one_sum_2)
		return 1;
	else if(one_sum_1 < one_sum_2)
		return -1;
	else if(one_sum_1 == one_sum_2){
		if(*ptr1 > *ptr2)
			return 1;
		else if(*ptr1 < *ptr2)
			return -1;
		else 
			return 0;
	}
	return 0;

}

int main(){
	long long numbers[MAXLEN];
	int len=0;
	while(scanf("%lld", &numbers[len]) != EOF){
		len++;
	}
	qsort(numbers, len, sizeof(long long), compare);

	for(int i=0; i<len; i++)
		printf("%lld\n", numbers[i]);

	return 0;
}



























