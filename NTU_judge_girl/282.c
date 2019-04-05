#include <stdio.h>

int main(){
	long long num;

	while(scanf("%lld", &num) != EOF){
		long long tmp = 1;
		int count = 0;
		for(int i=1; i<=63; i++)
		{
			if(num & tmp)
				count++;
			tmp = tmp<<1;
		}

		printf("%d\n", count);
	}

	return 0;
}