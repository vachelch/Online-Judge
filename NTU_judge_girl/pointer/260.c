#include <stdio.h>
#include <string.h>

int min (int a, int b){
	return a>b? a:b;
}
int main(){
	char fusion[127] = "";
	char string[127];

	while(scanf("%s", string) != EOF){
		int len_f = strlen(fusion);
		int len_s = strlen(string);
		int len = min(len_f, len_s);

		//check whether last i character in fusion is equal to former i character in string 
		for(int i=len; i>=0; i--){
			char * fus_start = fusion + (len_f-i);

			if(strncmp(fus_start, string, i) == 0){
				strcpy(fus_start, string);
				break;
			}
		}
	}

	printf("%s\n", fusion);
}























