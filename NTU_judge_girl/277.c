#include <stdio.h>

void print_digit(char *num, int width, int height, int len){
	int w = (width-3);
	int h = (height -3)/2;
	//row top
	for (int i = 0; i < len; ++i)
	{
		switch(num[i]){
			case('0'): case('2'): case('3'): case('5'): case('6'): case('7'): case('8'): case('9'): 
				printf(" ");
				for(int j=0; j<w;j++)
					printf("%c", num[i]);
				printf("  ");
				break;
			case('1'): case('4'): 
				for(int j=0; j<width;j++)
					printf(" ");
				break;
		}
	}
	printf("\n");

	//row upper
	for (int row = 0; row < h; ++row)
	{
		for (int i = 0; i < len; ++i)
		{
			switch(num[i]){
				case('0'): case('4'): case('7'): case('8'): case('9'): 
					printf("%c", num[i]);
					for(int j=0; j<w;j++)
						printf(" ");
					printf("%c ", num[i]);
					break;
				case('1'): case('2'): case('3'): 
					for(int j=0; j<w+1;j++)
						printf(" ");
					printf("%c ", num[i]);
					break;
				default:
					printf("%c", num[i]);
					for(int j=0; j<w+2;j++)
						printf(" ");
			}
		}
		printf("\n");
	}

	//row middle
	for (int i = 0; i < len; ++i)
	{
		switch(num[i]){
			case('0'): case('1'): case('7'):
				for(int j=0; j<width;j++)
					printf(" ");
				break;
			default:
				printf(" ");
				for(int j=0; j<w;j++)
					printf("%c", num[i]);
				printf("  ");
		}
	}
	printf("\n");

	//row lower
	for (int row = 0; row < h; ++row)
	{
		for (int i = 0; i < len; ++i)
		{
			switch(num[i]){
				case('0'): case('6'): case('8'): 
					printf("%c", num[i]);
					for(int j=0; j<w;j++)
						printf(" ");
					printf("%c ", num[i]);
					break;
				case('1'): case('3'): case('4'): case('5'): case('7'): case('9'): 
					for(int j=0; j<w+1;j++)
						printf(" ");
					printf("%c ", num[i]);
					break;
				default:
					printf("%c", num[i]);
					for(int j=0; j<w+2;j++)
						printf(" ");
			}
		}
		printf("\n");
	}

	//row bottom
	for (int i = 0; i < len; ++i)
	{
		switch(num[i]){
			case('0'): case('2'): case('3'): case('5'): case('6'): case('8'): 
				printf(" ");
				for(int j=0; j<w;j++)
					printf("%c", num[i]);
				printf("  ");
				break;
			default:
				for(int j=0; j<width;j++)
					printf(" ");
		}
	}
	printf("\n");
}

int main(){
	int width, height, len;
	char str[10] = "";
	
	while(scanf("%s", str) != EOF){
		scanf("%d%d", &width, &height);

		for(len = 0;str[len]!='\0'; len++);
		
		print_digit(str, width, height, len);
	}
	
	return 0;
}