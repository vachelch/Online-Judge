#include <stdio.h>
#include <assert.h>

void snake(const int *ptr_array[100][100], int m);
 
int main()
{
  int array[100][100], check[100][100];
  const int *ptr_array[100][100];
  int i, j, m;
 
  scanf("%d", &m);
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) {
      ptr_array[i][j] = &(array[i][j]);
      scanf("%d", &(array[i][j]));
      check[i][j] = array[i][j];
    }
 
  snake(ptr_array, m);
 
  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
      assert(check[i][j] == array[i][j]);
      assert((ptr_array[i][j] >= &array[0][0]) && (ptr_array[i][j] <= &array[99][99]));
      printf("%d ", *(ptr_array[i][j]));
    }
    printf("\n");
  }
 
  return 0;
}

void snake(const int *ptr_array[100][100], int m){
	const int *value[m*m];
	const int *tmp;

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j)
			value[i*m+j] = ptr_array[i][j];

	for (int i = m*m-1; i >= 0; --i)
		for (int j = 0; j < i; ++j)
		{	
			if(*value[j] > *value[j+1])
			{
				tmp = value[j+1];
				value[j+1] = value[j];
				value[j] = tmp;
			}
				
		}


	for (int i = 0; i < m; ++i)
	{
		if (i%2 == 0)
		{
			for (int k = 0; k < m; ++k)
				ptr_array[i][k] = value[i*m+k];
		}
		else{
			for (int k = 0; k < m; ++k)
				ptr_array[i][m-1-k] = value[i*m+k];
		}
	}
}














