#include <stdio.h>

int subsets_num = 0;
int num[15];
int n;

void subsets_(int k, int test){
	if(k == 0 && test == n)
		subsets_num++;
	
	if(test <n){
		subsets_(k-num[test], test+1);
		subsets_(k, test+1);
	}

}


int main(){
	int k;
	scanf("%d", &n);

	for(int i=0;i<n;i++)
		scanf("%d", &num[i]);

	while(scanf("%d", &k) != EOF){
		subsets_(k, 0);
		printf("%d\n", subsets_num);
		subsets_num = 0;
	}
}