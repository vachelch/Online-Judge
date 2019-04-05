#include <stdio.h>
#include <string.h>

int min_(int a, int b){
	return a<b? a:b;
}


int edit_distance(char *a, char *b){
	if(strlen(a) == 0)
		return strlen(b);
	if(strlen(b) == 0)
		return strlen(a);

	if(a[0] == b[0])
		return edit_distance(&a[1], &b[1]);
	else
		return 1 + min_(edit_distance(a, &b[1]), edit_distance(&a[1], b));
}

int main(){
	char strings[100][11];
	char string[11];
	int length = 0;

	while(scanf("%s", strings[length]) != EOF){
		length++;
	}

	//get the ID and distance of max pair of edit distance
	int min_ = 10;
	int id_1=1, id_2=2;
	for(int i=0; i< length-1; i++)
		for(int j=i+1; j< length; j++){
			int distance = edit_distance(strings[i], strings[j]);
			if (distance < min_){
				min_ = distance;
				id_1 = i+1;
				id_2 = j+1;
			}
		}

	printf("%d %d %d", min_, id_1, id_2);

	return 0;
}