#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char cur[128];
	char abbre[128];
	char * ptr = abbre;
	char preposition[4][5] = {"of", "and", "the", "at"};


	while(scanf("%s", cur)!= EOF){
		char end = 0;
		int len = strlen(cur);
		if(cur[len-1] == '.'){
			end = 1;
			cur[len-1] = '\0';
		}

		//check cur whether cur is "and" "of" etc
		int pre = 0;
		for(int i=0; i<4; i++)
			if(strcmp(cur, preposition[i]) == 0){
				pre = 1;
				break;
			}

		//if not, concatenate first char to abbre
		if(!pre){
			*ptr = toupper(cur[0]);
			ptr++;
		}
		if(end){
			*ptr = '\0';
			puts(abbre);
			ptr = abbre;
		}



	}
	return 0;


}






























