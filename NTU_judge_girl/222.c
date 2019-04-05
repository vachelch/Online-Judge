#include <stdio.h>
#include <climits>

int main(){
	long long unsigned int shelf = 0; 
	int book;

	while(scanf("%d", &book) != EOF){
		//from shelf
		int inshelf = 0;
		int index;
		long long unsigned int tmp = 255;

		//on shelf and which position
		for(int i=0; i<8; i++){
			if(((shelf >> 8*i) & tmp) == book){
				inshelf = 1;
				index = i+1;
				break;
			}
		}

		long long unsigned int long_book = book;
		if(inshelf){
			long long unsigned int front = shelf >> index*8 << index*8;
			long long unsigned int later = shelf << (8-index+1)*8 >> (8-index+1)*8;
			later = later << 8;
			shelf = long_book | front | later;
		}
		else{
			shelf = shelf<< 8;
			shelf = shelf | long_book;
		}
	}
	
	//print shelf
	long long unsigned int tmp = ULLONG_MAX;
	char cur;
	for(int i = 7; i>=0; i--){
		char cur = (tmp & shelf)>>(i*8);
		tmp = tmp >> 8;
		printf("%d", cur);
		if(i >= 1)
			printf(" ");
	}
	return 0;

}





































