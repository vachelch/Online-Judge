#include <stdio.h>
#include <stdlib.h>

int color_countries(int n, int N, int C, int *colors, int pairs[20][20]){
	if(n == N){
		for(int i=0; i<N; i++)
			printf("%d\n", colors[i]);
		exit(1);
	}

	//try all color
	for(int i =1; i<=C; i++){
		int conflict = 0;
		//for all contry have no conflict
		for(int j =0; j<N; j++){
			if(j == n)
				continue;
			if(pairs[n][j] == 1 && i == colors[j]){
				conflict = 1;
				break;
			}
		}

		if (!conflict){
			colors[n] = i;
			color_countries(n+1, N, C, colors, pairs);
			colors[n] = 0;
		}

	}

	return 0;

}


int main(){
	int N, C, P;
	scanf("%d %d %d", &N, &C, &P);
	int colors[N];
	int pairs[20][20];

	for(int i=0; i<N; i++){
		colors[i] = 0;
		for(int j=0; j<N; j++)
			pairs[i][j] = 0;
	}

	int index1, index2;
	for(int i=0; i<P; i++){
		scanf("%d %d", &index1, &index2);
		pairs[index1][index2] = 1;
		pairs[index2][index1] = 1;
	}

	int result = color_countries(0, N, C, colors, pairs);

	if(!result)
		printf("no solution.\n");
	return 0;
}































