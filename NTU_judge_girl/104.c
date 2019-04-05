#include <stdio.h>

int DA, DB, DC, EA, EB, EC, FA, FB, FC;

int solve(int a, int b, int c){
	if(a<0 || b<0 || c<0)
		return 0;
	if(a==0 && b==0 && c==0)
		return 1;

	return solve(a-DA, b-DB, c-DC) ||
		solve(a-EA, b-EB, c-EC) || 
		solve(a-FA, b-FB, c-FC);
	
}

void query(int n){
	if(n==0)
		return ;

	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if(solve(a, b, c))
		puts("yes");
	else 
		puts("no");
	query(n-1);
}


int main(){
	scanf("%d%d%d%d%d%d%d%d%d", &DA, &DB, &DC, &EA, &EB, &EC, &FA, &FB, &FC);

	int n;
	scanf("%d", &n);

	query(n);

	return 0;
}