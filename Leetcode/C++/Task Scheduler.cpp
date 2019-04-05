class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    	int l = tasks.size();

    	vector<int> count(26, 0);
    	for(int i=0; i<l; i++)
    		count[tasks[i] - 'A'] += 1;

    	int mx = -1;
    	int mx_count;

        for(int i=0; i<26; i++){
        	if(count[i] > mx){
        		mx = count[i];
        		mx_count = 1;
        	}
        	else if(count[i] == mx)
        		mx_count += 1;
        }

        return max(l, (mx-1)*(n+1) + mx_count);
    }
};