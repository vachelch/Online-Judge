class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly;
        ugly.push_back(1);

        int size = primes.size();
        int idxs[size] = {0};

        for(int i=1; i< n; i++){
        	int mn = INT_MAX;
        	for(int j=0; j< size; j++){
        		mn = min(mn, primes[j] * ugly[idxs[j]]);
        	}

        	ugly.push_back(mn);

        	for(int j=0; j< size; j++){
        		while(primes[j] * ugly[idxs[j]] <= mn) 
        			idxs[j] ++;
        	}
        }

        return ugly[n-1];
    }
};