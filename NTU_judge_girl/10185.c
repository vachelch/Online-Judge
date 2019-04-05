#include <stdio.h>

int main(){
	int N, M, P;
	long long unsigned code_arr[4];

	scanf("%d%d%d", &N, &M, &P);

	for(int i=0; i<M; i++)
		scanf("%llu", &code_arr[i]);

	for(int i = 0; i<P; i++){
		int tmp;
		scanf("%d", &tmp);
		char code = 0;
		code = code | tmp;

		//check each valid_code to find if there's a code correct(0 or 1)
		for(int j=0; j<N; j++){
			//any code is correct
			for(int k = 0; k<8; k++, j++){
				int flag =1, count = 0;

				char valid_code = code_arr[j/8]>>(7-k)*8;

				char result = code ^ valid_code;

				//check result, only 1 or 0 
				for(int l=0; l<8; l++){
					if(result & 1){
						count++;
						if(count > 1){
							flag = 0;
						}
					}
					result = result >>1;
				}

				if(flag)
					printf("%d\n", valid_code);

				if(j==N)
					break;
			}
		}
	}

	return 0;
}	





















