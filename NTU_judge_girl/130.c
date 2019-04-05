#include <stdio.h>
#include <string>
#include <stdlib.h>

void swap(string  a, string  b){
	string  tmp = a;
	a = b;
	b = tmp;
}

void is_similar_con13(string str1, string str2){
	if (!strcmp(str1, str2))
		printf("yes\n");
	else{
		int len = strlen(str1);
		int i = 0;
		int j = 0;
		int flag = 1;
		char c;

		while(i<len && j<len){
			if(str1[i] == str2[j]){
				i++;
				j++;
			}
			else if(flag == 1){
				flag --;
				c = str1[i];
				i++;
			}
			else if (flag == 0 && str2[j] == c){
				flag --;
				i ++;
				j ++;
			}
			else{
				printf("no\n");
				return;
			}
		}

		printf("yes\n");
	}
}

void is_similar_con2(string str1, string str2){
	int flag = 1;
	int i = 0, j = 0;
	int len = strlen(str1);

	while (i < len){
		if(str1[i] == str2[j]){
			i ++;
			j ++;
		}
		else if(flag == 1){
			j ++;
			flag --;
		}
		else{
			printf("no\n");
			return;
		}
	}
	printf("yes\n");
}

int main(){
	int n;
	char str1[81], str2[81];
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		scanf("%s%s", str1 ,str2);
		int len1 = strlen(str1);
		int len2 = strlen(str2);

		if (len1 == len2){
            is_similar_con13(str1, str2);
		}
		else if(abs(len1 - len2) == 1){
			if (len1 > len2)
				swap(str1, str2);
			is_similar_con2(str1, str2);
		}
		else
			printf("no\n");
	}

	return 0;
}