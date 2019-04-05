#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expense{
	int y;
	int m;
	int d;
	char category[33];
	int amount;
} Expense;


int cmp_date(const void * ptr1, const void * ptr2){
	Expense *day1 = *((Expense **)ptr1);
	Expense *day2 = *((Expense **)ptr2);

	if(day1->y > day2->y)
		return 1;
	else if(day1->y < day2->y)
		return -1;
	else if(day1->m > day2->m)
		return 1;
	else if(day1->m < day2->m)
		return -1;
	else if(day1->d > day2->d)
		return 1;
	else if(day1->d < day2->d)
		return -1;
	else {
		int cond = strcmp(day1->category, day2->category);
		if(cond > 0)
			return 1;
		else if(cond < 0)
			return -1;
		else 
			return 0;
	}
}

int same_expense(Expense *day1, Expense *day2){
	return (day1->y == day2->y && day1->m == day2->m && day1->d == day2->d && !strcmp(day1->category, day2->category));

}

int main(){
	Expense *expenses[10000];
	int y;
	int m;
	int d;
	char category[33];
	int amount;

	int len=0;
	while(scanf("%d%d%d%s%d", &y, &m, &d, category, &amount) != EOF){
		expenses[len] = (Expense *) malloc(sizeof(struct expense));
		expenses[len]->y = y;
		expenses[len]->m = m;
		expenses[len]->d = d;
		strcpy(expenses[len]->category, category);
		expenses[len]->amount = amount;

		len++;
	}

	qsort(expenses, len, sizeof(Expense *), cmp_date);

	Expense * exp_sum[len];

	int k = 1;
	Expense *last = expenses[0];
	exp_sum[0]  = expenses[0];
	for(int i=1; i<len; i++){
		if(same_expense(last, expenses[i])){
			exp_sum[k-1]->amount += expenses[i]->amount;
			last = expenses[i];
		}
		else{
			exp_sum[k] = expenses[i];
			last = expenses[i];
			k++;
		}
	}

	for(int i=0; i<k; i++){
		printf("%d %d %d %s %d\n", exp_sum[i]->y, exp_sum[i]->m, exp_sum[i]->d, exp_sum[i]->category, exp_sum[i]->amount);
	}
		
}
























