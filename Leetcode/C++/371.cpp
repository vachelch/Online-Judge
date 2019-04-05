class Solution {
public:
    int getSum(int a, int b) {
    	while (b != 0){
    		int c = a ^ b;
			int d = a & b;
			d = d << 1;
			
			a = c;
			b = d;
    	}
    	return a;
    }
};