#include <stdio.h>
#include <ctype.h>

int main(){
	char c;
	char str[100] = "";
	char space[100] = "";
	int flag = 0;

	int i = 0;
	int j = 0;
	while(scanf("%c", &c) != EOF){
		if(c == '\n'){
			for (int k = 0; k < i; ++k)
				printf("%c", str[k]);
			printf("\n");
			i = j = flag = 0;
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
	// scanf("%s", str);
	// int i =0;
	// while(str[i] != '\0'){
	// printf("%s\n", str);
	return 0;
}