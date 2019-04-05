#include <stdio.h>
#include <ctype.h>

int main(){
	char c;
	char str[100] = "";
	char space[100] = "";

	int i = 0;
	int j = 0;
	int flag = 0;
	while(scanf("%c", &c) != EOF){
		if(c == '\n'){
			for (int k = 0; k < i; ++k)
			{
				printf("%c", str[k]);
			}
			printf("\n");
			i = j = 0;
            flag = 0;
		}
		else if(isspace(c)){
			space[j] = c;
			j++;
		}
		else{
            if(flag){
                for(int k = 0; k<j; k++, i++)
                    str[i] = space[k];
            }
            flag = 1;
			str[i] = c;
			j = 0;
			i++;
		}
	}
	return 0;
}
