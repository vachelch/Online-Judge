#include <stdio.h>

int main(){
	char cur, cur1, cur2;
	int count = 0;
	

	cur = getchar();
	while( cur != EOF){
		char current = 'a';

		if(cur == '.'){
			
			if((cur1 = getchar())==' '){
				if((cur2 = getchar()) == ' '){
					count++;
				}
				else if(cur2 == '\n'){
					int flag = 1;
					while((cur2 = getchar())!= EOF){
						if(cur2 != ' ' && cur2 != '\n'){
							flag = 0;
							break;
						}				
					}
					if(flag){
						count++;
					}
				}
				else if(cur2 == '.'){
					current = '.';
				}
				
			}
			else if(cur1 == '\n'){
				count++;
			}
			else if(cur1 == '\0'){
				count++;
			}
			else if(cur1 == '.'){
				current = '.';
			}

		}
		if(current == '.'){
			cur = current;
			continue;
		}
		cur = getchar();
	}

	printf("%d\n", count);

	return 0;
}