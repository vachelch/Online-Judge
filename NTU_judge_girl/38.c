#include <stdio.h>

int hasmagic(int power,int a, int b, int c, int A, int B, int C){
	for(int i = 0; i<= a; i++)
		for (int j=0; j<= b; j++)
	 		for(int k =0; k<=c; k++) 
	 			if(power == i*A + j*B + k*C)
	 				return 1;
	return 0;
}

int main(){
	int line;
	scanf("%d", &line);

	int power,a, b, c, A, B, C;
	for(int i=0; i<line; i++){
		scanf("%d%d%d%d%d%d%d", &power, &a, &b, &c, &A, &B, &C);
		if(hasmagic(power,a, b, c, A, B, C))
			puts("yes");
		else 
			puts("no");
	}
	return 0;
}