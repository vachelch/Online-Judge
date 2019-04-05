class Solution {
public:
    int lastRemaining(int n) {
    	int left = 1, right = n;
    	int dir = 1;
    	int diff = 1;
        while(left < right){
        	if (dir == 1){
        		if ((right - left) % (2*diff) == 0)
        			right -= diff;
        		left += diff;
        	}
        	else{
        		if ((right - left) % (2*diff) == 0)
        			left += diff;
        		right -= diff;
        	}
        	dir = 1 - dir;
        	diff *= 2;
        }

        return left;
    }
};