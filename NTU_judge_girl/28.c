#include <stdio.h>
int sum(int m){
	if(m == 1)
		return 1;
	else
		return sum(m-1) + m*m;
}

int main(){
	int m;
	scanf("%d", &m);	
	printf("%d\n", sum(m));
	return 0;
}