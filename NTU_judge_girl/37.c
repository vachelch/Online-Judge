#include <stdio.h>

int value(int type, int width, int height, int length);
int GCD(int a, int b){
	if(a%b ==0)
		return b;
	else
		return GCD(b, a%b);
}

int main(int argc, char const *argv[])
{
	int t, w, h, l;
	scanf("%d%d%d%d", &t, &w, &h, &l);
	printf("%d\n", value(t, w, h, l));
	return 0;
}

int value(int type, int width, int height, int length){
	int price, total;
	int volume = width * height * length;
	switch(type){
		case 79:
			price = 30;
			break;
		case 47:
			price = 10;
			break;
		case 29:
			price = 4;
			break;
		case 82:
			price = 5;
			break;
		case 26:
			price = 3;
			break;
		case 22:
			price = 9;
			break;
		default:
			return -1;
	}
	if(width<=0 || height <= 0 || length <= 0)
		return -2;
	
	// find the GCD of width height length
	int gcd = GCD(GCD(width, height), length);

	total = price*volume*gcd*gcd*gcd;
	return total;
	
}




































