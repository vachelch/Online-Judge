#include <stdio.h>

int row, col;
int ways = 1;

int corner(int r, int c){
	if(r == 1 && c == col){
		return 1;
	}

	if(r>1 && c<col)
		ways =  corner(r - 1, c) + corner(r, c + 1);
	else if(r>1)
		ways = corner(r - 1, c);
	else
		ways = corner(r, c + 1);

	return ways;
}

int main(){

	scanf("%d%d", &row, &col);
	printf("%d\n", corner(row, 1));

	return 0;
}