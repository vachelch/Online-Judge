#include <stdio.h>

int main(){
	int m, n;
	char one[2], zero[2];
	unsigned int A[1024];

	scanf("%d%d%s%s", &m, &n, one, zero);
	int len = m*n/32;
	int remain = m*n % 32;

	for(int i = 0; i< len; i++)
		scanf("%d", &A[i]);
	if(remain != 0)
		scanf("%d", &A[len++]);

	int cur = 1;
	int num = 0;

	unsigned int tmp = 1<<31;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(tmp & A[num])
				printf("%s", one);
			else 
				printf("%s", zero);

			//update
			tmp = tmp >> 1;
			cur++;

			if(cur > 32){
				num++;
				cur = 1;
				tmp = 1<<31;
			}
		}
		printf("\n");
	}
		
}





























