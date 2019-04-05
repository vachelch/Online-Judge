#include <stdio.h>

int factorial(int n){
	int mul = 1;
	for(int i=n; i>0; i--){
			mul *= i;
	}
	return mul;
}

int Cnk(int n, int k){
	int n_fac = factorial(n);
	int k_fac = factorial(k);
	int n_k = factorial(n-k);
	if(n==0 && k== 0)
		return 0;
	else if(k==0 || k==n)
		return 1;
	else 
		return n_fac/k_fac/n_k;
}

int main(int argc, char const *argv[])
{
	int n, k, sum = 0;
	scanf("%d%d", &n, &k);
	for(int i=0; i<=k; i++){
		sum += Cnk(n, i);
	}
	printf("%d\n", sum);
	// printf("%d\n", Cnk(5,0));
	return 0;
}