#include <stdio.h>
#include <stdlib.h>
#define MAXCITY 100000

typedef struct city{
	int x;
	int y;
} City;

int start_x = 0, start_y = 0;
int nearest_x = 0, nearest_y = 0;

int cmp(const void *city1, const void *city2){
	City *ptr1 = *((City **)city1);
	City *ptr2 = *((City **)city2);

	int distance1 = (ptr1->x - start_x)*(ptr1->x - start_x) + (ptr1->y - start_y)*(ptr1->y - start_y);
	int distance2 = (ptr2->x - start_x)*(ptr2->x - start_x) + (ptr2->y - start_y)*(ptr2->y - start_y);

	if(distance1 > distance2)
		return -1;
	else if(distance1 < distance2)
		return 1;
	else{
		if(ptr1->x > ptr2->x)
			return -1;
		else if(ptr1->x < ptr2->x)
			return 1;
		else{
			if(ptr1->y > ptr2->y)
				return -1;
			else if(ptr1->y < ptr2->y)
				return 1;
			else
				return 0;
		}	
	}

}

int main(){
	City * citys[MAXCITY];
	int len=0;
	int x, y;

	//read input
	while(scanf("%d%d", &x, &y) != EOF){
		citys[len]= (City *)malloc(sizeof(struct city));
		citys[len]->x = x;
		citys[len]->y = y;
		len++;
	}

	int sum = 0;

	int city_len = len;
	//sort distance in decending order
	qsort(citys, city_len, sizeof(City *), cmp);	

	while(city_len > 0){
		//last city has nearest distance
		nearest_x = citys[city_len-1]->x;
		nearest_y = citys[city_len-1]->y;
		int dist  = (nearest_x - start_x) * (nearest_x - start_x) + (nearest_y - start_y) * (nearest_y - start_y); 
		sum += dist;
		//print process
		// printf("      %d %d\n", nearest_x, nearest_y);

		//from last city start
		start_x = nearest_x;
		start_y = nearest_y;
		//delet last city from qsort
		city_len--;
	}

	printf("%d\n", sum);
	return 0;
}
















