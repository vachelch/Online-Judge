#include <stdio.h>

int main(){
	int num;

	while(scanf("%d", &num) != EOF){
		int count=0, tmp=1,last =0;
		int max = 0;
		
		for(int i=1;i<=31;i++){
			if(last == 1){
				if(tmp & num){
					count++;
					if(max < count){
						max = count;
					}
				}
				else
					last = 0;
			}
			else{
				if(tmp & num){
					last = 1;
					count = 1;
					if(count > max)
						max = count;
				}
			}
			tmp = tmp << 1;
		}

		printf("%d\n", max);
	}

	return 0;
}