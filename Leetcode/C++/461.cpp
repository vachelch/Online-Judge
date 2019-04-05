class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int dist = 0;
        while(z){
        	dist += z ^ 1;
        	z = z >> 1;
        }
    }
};