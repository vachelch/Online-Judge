#include <stdio.h>
int weight[20], value[20];
int max = 0;
int n,w;

void bag(int cur, int w, int v){
	if (cur+1 > n){
		if(v>max)
			max = v;
		return;
	}

	if(w-weight[cur] >= 0)
		bag(cur+1, w-weight[cur], v+value[cur]);
	bag(cur+1, w, v);
	
}

int main(){
	scanf("%d%d", &n, &w);
	for(int i=1; i<n; i++){
		scanf("%d%d", &weight[i], &value[i]);
		bag(0, w, 0);
	}
	printf("%d\n", max);

	return 0;
}