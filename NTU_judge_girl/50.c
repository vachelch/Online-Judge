#include <stdio.h>
#include <stdlib.h>

int overlapArea(int A, int B, int C, int D, int E, int F, int G, int H);
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}

int main(int argc, char const *argv[])
{
	int A, B, C, D, E, F, G, H , I, J, K, L;

	scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &A, &B, &C, &D, &E, &F, &G, &H , &I, &J, &K, &L);

	int area1 = (C-A)*(D-B);
	int area2 = (G-E)*(H-F);
	int area3 = (K-I)*(L-J);//IJ KL
	int overlap12 = overlapArea(A, B, C, D, E, F, G, H);
	int overlap13 = overlapArea(A, B, C, D, I, J, K, L);
	int overlap23 = overlapArea(E, F, G, H , I, J, K, L);
	int overlap123 = 0;

	if(overlap12 && overlap23 && overlap13){
		//get overlap coordinate of 12
		int leftBott_x = max(A, E); 
		int leftBott_y = max(B, F);
		int rightTop_x = min(C, G);
		int rightTop_y = min(D, H);
		overlap123 = overlapArea(leftBott_x, leftBott_y, rightTop_x, rightTop_y, I, J, K, L);
	}
	printf("%d\n", area1 + area2 + area3 - overlap12 - overlap13 - overlap23 + overlap123);
	// printf("%d\n", overlapArea(-3, 0, 3, 4, 0, -1, 9, 2));
	
	return 0;

}


int overlapArea(int A, int B, int C, int D, int E, int F, int G, int H){
	int len1, len2;
	int aa = max(A, E);
	int bb = min(C, G);
	if(bb>aa)
		len1 = bb-aa;
	else 
		return 0;

	int cc = max(B, F);
	int dd = min(D, H);
	if(dd>cc){
		len2 = dd-cc;
	}
	else 
		return 0;
	return len1*len2;
}
