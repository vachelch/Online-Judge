#include <stdio.h>

void fill_array(int *ptr[], int n);

int main() {
    int arr[100] = {};
    int *ptr[100];
    int n = 6, m = 0;
    int A[100] = {0, 5, 6, 9, 3, 12};
    for (int i = 0; i < n; i++) {
        ptr[i] = &arr[A[i]];
        if (A[i] > m)    m = A[i];
    }
    fill_array(ptr, n);
    for (int i = 0; i <= m; i++)
        printf("%d%c", arr[i], " \n"[i==m]);
    return 0;
}

void fill_array(int *ptr[], int n){
	int index[n];
	int *asc_ptr[n];

	for (int i = 0; i < n; ++i){
		asc_ptr[i] = ptr[i];
		index[i] = i;
	}
	
	int *temp;
	int temp_i;
	//sort position by ascending
	for (int i = n-1; i >0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if(asc_ptr[j]>asc_ptr[j+1]){
				temp = asc_ptr[j+1];
				asc_ptr[j+1] = asc_ptr[j];
				asc_ptr[j] = temp;

				temp_i = index[j+1];
				index[j+1] = index[j];
				index[j] = temp_i;
			}
		}
	}

	//value pointed by ptr
	for (int i = 0; i < n; ++i)
		*ptr[i] = i;

	//value not pointed by ptr
	int *start_pos, *end_pos;
	int sum;
	int period;
	for (int i = 0; i < n-1; ++i)
	{
		start_pos = asc_ptr[i];
		end_pos = asc_ptr[i+1];
		sum = index[i] + index[i+1];

		period = end_pos - start_pos;

		for (int j = 1; j < period; ++j)
			*(start_pos+j) = sum;
	}


}