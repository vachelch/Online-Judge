#include <stdio.h>
// int type1[3] = {1,4,2};
// int type4[3] = {1,4,3};
// int type2[3] = {1,3,2};
// int type3[3] = {4,3,2};

void tile(int shape, int x, int y, int edge){
	if(edge == 2){
		printf("%d %d %d\n",shape, x, y);
		return ;
	}

	switch(shape){
		case 1:
			tile(1, x, y, edge/2);
			tile(1, x - edge/4, y - edge/4, edge/2);
			tile(4, x - edge/4, y + edge/4, edge/2);
			tile(2, x + edge/4, y - edge/4, edge/2);
			break;
		case 2:
			tile(2, x, y, edge/2);
			tile(1, x - edge/4, y - edge/4, edge/2);
			tile(3, x + edge/4, y + edge/4, edge/2);
			tile(2, x + edge/4, y - edge/4, edge/2);
			break;
		case 3:
			tile(3, x, y, edge/2);
			tile(4, x - edge/4, y + edge/4, edge/2);
			tile(3, x + edge/4, y + edge/4, edge/2);
			tile(2, x + edge/4, y - edge/4, edge/2);	
			break;
		case 4:
			tile(4, x, y, edge/2);
			tile(1, x - edge/4, y - edge/4, edge/2);
			tile(4, x - edge/4, y + edge/4, edge/2);
			tile(3, x + edge/4, y + edge/4, edge/2);
			break;
	}

	return ;
}

int main(){
	int n,m;

	scanf("%d%d", &n, &m);
	tile(1, n/2, n/2, n);

	return 0;
}