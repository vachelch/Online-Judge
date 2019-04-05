#include <stdio.h>
#include <string.h>

int main(){
	int m;
	scanf("%d", &m);

	//store a line, words num, character number, line len= 0
	char line[258] = "";
	int num = 0, total = 0;
	char word[256];
	char *ptr = word;
	int len = 0;
	int characters = 0;

	while(scanf("%s", word) != EOF){
		int len_word = strlen(word);
		num++;
		characters += len_word; 
		total = characters + num-1;

		//len

		if(total > m){
			int space_per_word = (m - total + len_word+1)/(num-2);
			int remain_space = (m - total + len_word+1)%(num - 2);

			char *start = strtok(line, "/");
			//print line
			for(int i= 0; i<remain_space; i++){
				//print this word
				printf("%s", start);
				//print space(spaces per word + remain space in front)
				for(int j=0; j<=space_per_word+1; j++)
					printf(" ");
				start = strtok(NULL, "/");
			}
			for(int i=0; i<num-1-remain_space-1; i++){
				//print this word
				printf("%s", start);
				//print space(spaces per word + remain space in front)
				for(int j=0; j<=space_per_word; j++)
					printf(" ");
				start = strtok(NULL, "/");
			}
			//print last word
			printf("%s\n", start);
			
			//reinitialize line and add word to line, num, total
			line[0] = '/';
			strcpy(&line[1], word);
			num = 1;
			characters = len_word;
			line[len_word+1] = '\0';
		}
		else{
			int len = total+2;
			//add word to line
			line[len - len_word-1-1] = '/';
			strcpy(&line[len - len_word-1], word);
			line[len-1] = '\0';
		}

	}
	//print last line
	char *start = strtok(line, "/");

	if(num == 1){
		for(int i=0; i< m-strlen(word); i++)
			printf(" ");
		printf("%s\n", start);
	}
	else{
		int space_per_word = (m - total)/(num-1);
		int space_remain = (m - total)%(num-1);
		
		int c = 1;
		while(start != NULL){
			if(c<num){
				printf("%s", start);
				for(int i=0; i<=space_per_word; i++)
					printf(" ");
				if(c<=space_remain)
					printf(" ");
				c++;
				start = strtok(NULL, "/");
			}
			else
				break;
		}
		printf("%s\n", start);
	}
	return 0;
}













