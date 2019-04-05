/********************************/
/*****  main realize qsort  *****/
/********************************/

// #include <stdio.h>
// #include <stdlib.h>

// int cmp(const void * ptr1, const void * ptr2){
// 	int * a = (int *) ptr1;
// 	int * b = (int *) ptr2;

// 	return b[0] - a[0];
// }

// void swap(int *ptr1, int *ptr2){
// 	int tmp = ptr1[0];
// 	ptr1[0] = ptr2[0];
// 	ptr2[0] = tmp;

// 	tmp = ptr1[1];
// 	ptr1[1] = ptr2[1];
// 	ptr2[1] = tmp;
// }

// void q_sort(int chr[][2], int l, int r){
// 	if (l < r){
// 		int i = l-1;
// 		int pivot = r;

// 		for(int k=l; k<=r; k++){
// 			if (chr[k][0] >= chr[pivot][0]){
// 				i ++;
// 				swap(chr[k], chr[i]);
// 			}
// 		}
	
// 		q_sort(chr, l, i-1);
// 		q_sort(chr, i+1, r);
// 	}
// }

// int main(){
// 	char s[] = "abbcccddddeeeeeffffff";
// 	int chr[26 * 2][2] = {0};

// 	for(int i=0; i<26; i++)
// 		chr[i][1] = 'a' + i;
// 	for(int i=0; i<26; i++)
// 		chr[i+26][1] = 'A' + i;

// 	int i = 0;
// 	while(s[i] != '\0'){
// 		if ('a'<= s[i] && s[i] <= 'z'){
// 			int idx = s[i] - 'a';
// 			++ chr[idx][0];
// 		}
// 		else{
// 			int idx = s[i] -'A' + 26;
// 			++ chr[idx][0];
// 		}

// 		++ i;
// 	}

// 	// qsort(chr, 52, sizeof(chr[0]), cmp);
// 	q_sort(chr, 0, 51);

// 	for(int i=0; i<52; i++){
// 		while(chr[i][0] --)
// 			printf("%c", chr[i][1]);
// 	}
// 	printf("\n");

// 	return 0;

// }



int cmp(const void * ptr1, const void * ptr2){
	int * a = (int *) ptr1;
	int * b = (int *) ptr2;

	return b[0] - a[0];
}

char* frequencySort(char* s) {
    int chr[256][2] = {0};

	for(int i=0; i<256; i++)
		chr[i][1] = i;

	int i = 0;
	while(s[i] != '\0'){
		chr[s[i]][0] ++;
		++ i;
	}

	qsort(chr, 256, sizeof(chr[0]), cmp);

	int len = 0;
	for(int i=0; i<256; i++){
		while(chr[i][0] --)
			s[len++] = chr[i][1];
	}

	return s;
}










