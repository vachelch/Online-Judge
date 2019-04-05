#include <stdio.h>

int row, col;
int path[12][12]={0};
int ways = 0;

int corner(int r, int c){
	if(r == 1 && c == col){
		return 1;
	}

	if(r>1 && c<col && path[r-1][c] && path[r][c+1])
		ways = corner(r - 1, c) + corner(r, c + 1);
	else if(r>1 && path[r-1][c])
		ways = corner(r - 1, c);
	else if(c<col && path[r][c+1])
		ways = corner(r, c + 1);
	else 
		return 0;

	return ways;
}

int main(){

	scanf("%d%d", &row, &col);
	for(int i=1; i<=row; i++)
		for(int j=1;j <=col; j++)
			scanf("%d", &path[i][j]);

	printf("%d\n", corner(row, 1));

	return 0;
}