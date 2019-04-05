class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
    	set<int> nums;
        for(int i=0; i< A.size(); i++)
        	nums.insert(A[i]);

        int res = 0;
        for(int i=0; i< A.size() - 2; i++){
        	for(int j=i+1; j< A.size()-1; j++){
        		int count = 2;
        		int a = A[i], b = A[j];
        		while(nums.find(a + b) != nums.end()){
        			int tmp = a + b;
        			a = b;
        			b = tmp;
        			count += 1;
        			res = max(count, res);
        		}
        	}
        }

        if (res < 3) return 0;
        return res;	
    }
};