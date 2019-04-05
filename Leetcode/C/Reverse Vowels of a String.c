#include <string.h>

char* reverseVowels(char* s) {
	int ptr1 = 0;
	int ptr2 = strlen(s)-1;

	while(ptr1 <ptr2){
		while s[ptr1] not in vowel
			ptr1 ++;
		while s[ptr2] not in vowel
			ptr2 --

		int tmp = s[ptr2]
		s[ptr2] = s[ptr1]
		s[ptr1] = tmp
	}
	return s

}