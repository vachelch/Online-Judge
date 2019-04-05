#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
	int gcd(int m, int n){
		while(n != 0){
			int r = m % n;
			m = n;
			n = r;
		}

		return m;
	}
	int lcm(int m, int n){
		return m * n / gcd(m, n);
	}
    int nthMagicalNumber(int N, int A, int B) {
    	long long r = pow(10, 14);
    	long long l = min(A, B);

    	while(l < r){
    		long long m = (l + r)/2;
    		if (m/A + m/B - m/lcm(A, B) < N)
    			l = m + 1;
    		else
    			r = m;
    	}

    	return l % 1000000007;
    }
};

int main(){
	Solution s;
	cout << s.nthMagicalNumber(1000000000, 40000, 40000) << endl;
}