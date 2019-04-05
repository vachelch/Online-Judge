#include <stdio.h>
#include <stdlib.h>

typedef struct date{
	int y;
	int m;
	int d;
} Date;

int cmp(const void * ptr1, const void * ptr2){
	Date * day1 = *((Date **)ptr1);
	Date * day2 = *((Date **)ptr2);

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
	else
		return 0;
}

int main(){
	int n;
	Date *dates[1000000];

	scanf("%d", &n);
	for(int i=0; i<n; i++){
		dates[i] = (Date *) malloc(sizeof(struct date));
		scanf("%d%d%d", &dates[i]->y, &dates[i]->m, &dates[i]->d);
	}

	qsort(dates, n, sizeof(Date *), cmp);

	// printf("\n\n");

	for(int i=0; i<n; i++)
		printf("%d %d %d\n", dates[i]->y, dates[i]->m, dates[i]->d);
	
	return 0;
}