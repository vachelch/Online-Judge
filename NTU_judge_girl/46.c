#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
	char command[7];
	char word[50000] = "";
	char *left = word;
	char *right = word;
	int len = 0;

	while(scanf("%s", command) != EOF){
		char param[6];
		char val[2];

		if(strcmp(command, "insert") == 0){
			scanf("%s", param);
			int k = atoi(param);
			if(strcmp(param, "left") == 0){
				scanf("%s", val);
				strcpy(left+1, word);
				*left = val[0];
				len++;
			}
			else if(strcmp(param, "right") == 0){
				scanf("%s", val);
				word[len] = val[0];
				word[len+1] = '\0';
				len++;
			}
			else if(isdigit(param[0])){
				scanf("%s", val);
				strcpy(left+k, left+k-1);
				*(left+k-1) = val[0];
				len++;
			}

		}
		else if(strcmp(command, "delete") == 0){
			scanf("%s", param);
			int k = atoi(param);
			if(strcmp(param, "left") == 0){
				strcpy(left, left+1);
				len--;
			}
			else if(strcmp(param, "right") == 0){
				word[len-1] = '\0';
				len--;
			}
			else if(isdigit(param[0])){
				strcpy(left+k-1, left+k);
				len--;
			}
		}
	}
	int max = -1;
	int count = 0;
	char last;
	char output[50000];
	int num=0;

	for(int i = 0; i< len; i++)
	{
		if(isalnum(last) && word[i] == last){
			count++;
			if(count > max){
				max = count;

				//a new output list
				output[0] = last;
				output[1] = '\0';
				count = 1;
				num = 1;
			}
			else if(count == max){
				output[num] = word[i];
				num++;
			}
		}
		else{
			count = 1;
			last = word[i];
			if(count >= max){
				output[num] = word[i];
				output[num+1] = '\0';
				num++;
			}
		}
	}

	for (int i = 0; i < num; ++i)
		printf("%c ", output[i]);
	printf("%d", max);

	return 0;
}



























