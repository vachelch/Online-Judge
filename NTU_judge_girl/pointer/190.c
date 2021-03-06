#include <stdio.h>

int evaluate_f(int *iptr[], int n, int *index);

int main(){
  int a[] = { 9, 7 };
  int b[] = { 3, 2 };
  int c[] = { 3, 2 };
  int d[] = { 9, 7 };
  int *iptr[] = { a, b, c, d };
  int max, index;
  max = evaluate_f(iptr, 4, &index);
  printf("%d %d\n", max, index);
}

int evaluate_f(int *iptr[], int n, int *index){
	int max = -2000000000, y;

	for (int i = 0; i < n; ++i)
	{
		int y = 4*(iptr[i][0]) - 6*iptr[i][1];
		if(y > max){
			max = y;
			*index = i;
		}
	}
	return max;
}