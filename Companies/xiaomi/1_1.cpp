class Solution {
public:
    /**
     * 获得两个整形二进制表达位数不同的数量
     * 
     * @param m 整数m
     * @param n 整数n
     * @return 整型
     */
    int countBitDiff(int m, int n) {
    	int cur = 1;
    	int cnt = 0;
    	for(int i=0; i< 32; i++){
    		if ((cur & m) != (cur & n)) cnt ++;
    		cur <<= 1;
    	}

    	return cnt;
    }
};