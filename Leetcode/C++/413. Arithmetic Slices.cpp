class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
    	vector<int> memory;
    	int len = 2;
        for(int i=2; i< A.size(); i++){
        	if (A[i] + A[i-1] == 2 * A[i]){
        		len += 1;
        	}
        	else if(len > 2){
        		memory.push_back(len);
        		len = 2;
        	}
        }

        if (len > 2)
        	memory.push_back(len);

        int res = 0;
        for(int i=0; i< memory.size(); i++){
        	res += (memory[i] - 1) * (memory[i] - 2) / 2;
        }

        return res;
    }
};