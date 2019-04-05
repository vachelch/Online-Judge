#include <stdio.h>

int main(){
	int num;
	int alpha[32];

	while(scanf("%d", &num) != EOF){
		int tmp = 1;
		int count = 0;
		for(int i=1; i<=31; i++)
		{
			if(num & tmp)
				count++;
			tmp = tmp<<1;
		}

		printf("%d\n", count);
	}

	return 0;
}