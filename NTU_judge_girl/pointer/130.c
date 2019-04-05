#include <stdio.h>
#include <string.h>

int main(){
	int n;
	scanf("%d", &n);
	for(int k=0; k<n; k++){
		char word1[40], word2[40];
		scanf("%s%s", word1, word2);

		if(strcmp(word1, word2) == 0){
			printf("yes\n");
		}
		else if(strlen(word1) == strlen(word2)){
			char tmp;
			for(int i=strlen(word1)-1; i>=1; i--){
				tmp = word2[i];
				word2[i] = word2[i-1];
				word2[i-1] = tmp;
				if (strcmp(word1, word2) == 0)
				{
					printf("yes\n");
					break;
				}	
				else{
					tmp = word2[i];
					word2[i] = word2[i-1];
					word2[i-1] = tmp;
				}
				if(i == 1)
					printf("no\n");

			}
				
		}
		else if(strlen(word1) - strlen(word2) == 1){
			int len = strlen(word1);
			char cur = word1[len-1];
			word1[len-1] = '\0';
			if(strcmp(word1, word2) == 0){
				printf("yes\n");
				continue;
			}
			else
				word1[len-1] = cur;

			for(int i=strlen(word1)-2; i>=0; i--){
				//drop word1[i] if i != lenstr(word1)-1
				cur = word1[i];
				for(int j=i;j<=len-2; j++)
					word1[j] = word1[j+1];
				word1[len-1] = '\0';
				if(strcmp(word1, word2) == 0){
					printf("yes\n");
					break;
				}
				else{
					for(int j=len-2;j>=i; j--)
						word1[j+1] = word1[j];
					word1[i] = cur;
				}
			}

		}
		else if(strlen(word1) - strlen(word2) == -1){
			int len = strlen(word2);
			char cur2 = word2[len-1];
			word2[len-1] = '\0';
			if(strcmp(word1, word2) == 0){
				printf("yes\n");
				continue;
			}
			else
				word2[len-1] = cur2;

			for(int i=strlen(word2)-2; i>=0; i--){
				//drop word2[i] if i != lenstr(word2)-1
				cur2 = word2[i];
				for(int j=i;j<=len-2; j++)
					word2[j] = word2[j+1];
				word2[len-1] = '\0';
				if(strcmp(word1, word2) == 0){
					printf("yes\n");
					break;
				}
				else{
					for(int j=len-2;j>=i; j--)
						word2[j+1] = word2[j];
					word2[i] = cur2;
				}
			}
		}
		else{
			printf("no\n");
		}
	
	}
	return 0;
}


















