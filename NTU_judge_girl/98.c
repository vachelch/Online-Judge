#include <stdio.h>
#include <string.h>

struct food{
	char name[64];
	int ing_num;
	char ingredient[10][64];
};

typedef struct food Food;

int main(){
	int n, m;
	int ind;

	scanf("%d", &n);
	Food all_food[n];
	for(int i = 0; i< n; i++){
		scanf("%s%d", all_food[i].name, &all_food[i].ing_num);
		for(int j=0; j< all_food[i].ing_num; j++){
			scanf("%s", all_food[i].ingredient[j]);
		}
	

	scanf("%d", &m);
	for(int loop=0; loop<m; loop++){
		char food_a[64], food_b[64];
		int a, b;
		scanf("%s%s", food_a, food_b);
		int a_assigned = 0;

		//find the inde of a, b in all_food respectively
		for(int j = 0; j<n; j++){
			if(strcmp(food_a, all_food[j].name) == 0)
				a = j;
			else if(strcmp(food_b, all_food[j].name) == 0)
				b = j;
		}

		//find the same ingredient between food_a and food_b and store them in same_ing[];
		char *same_ing[10];
		int count = 0;
		int no_one = 1;

		for(int i=0; i<all_food[a].ing_num; i++)
			for(int j=0; j<all_food[b].ing_num; j++){
				if(strcmp(all_food[a].ingredient[i], all_food[b].ingredient[j]) == 0){
					same_ing[count++] = all_food[a].ingredient[i];
					no_one = 0;
				}
			}

		//sort string and output
		if(no_one)
			printf("nothing\n");
		else if(count ==1){
			printf("%s\n", same_ing[0]);
		}
		else{
			for(int i=count-2; i>=0; i--)
				for(int j = 0; j<=i; j++){
					char *tmp;
					if(strcmp(same_ing[j], same_ing[j+1]) > 0){
						tmp = same_ing[j];
						same_ing[j] = same_ing[j+1];
						same_ing[j+1] = tmp;
					}
				}

			for (int j = 0; j < count; ++j){
				printf("%s", same_ing[j]);
				if(j+1<count)
					printf(" ");
				else
					puts("");
			}
		}
		
	}

	return 0;

}


















