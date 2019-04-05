class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int l = arr.size();
        int count = 0;
        int maxn = -1;

        for(int i=0; i < l; i++){
        	maxn = max(maxn, arr[i]);
        	if(maxn == i)
        		count ++;
        }
        return count;
    }
};