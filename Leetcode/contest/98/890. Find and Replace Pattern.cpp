class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int dist_P[26] = {0};

        string pttn = "";
        for(int i=0; i< pattern.size(); i++){
        	int idx = pattern[i] - 'a';
        	
        	if (dist_P[idx] == 0)
        		pttn += "0";
        	else
        		pttn +=  to_string(i+1 - dist_P[idx]);
        	dist_P[idx] = i+1;
        }
        // cout<< pattern << " " << pttn << endl;

        vector<string> res;
        int pt_size = pattern.size();

        for(auto word: words){
        	if (word.size() != pt_size) continue;

        	string pttn_w = "";
        	int dist_W[26] = {0};
	        for(int i=0; i< word.size(); i++){
	        	int idx = word[i] - 'a';
	        	
	        	if (dist_W[idx] == 0)
	        		pttn_w += "0";
	        	else
	        		pttn_w += to_string(i+1 - dist_W[idx]);
	        	dist_W[idx] = i+1;
	        }

	        if (pttn_w == pttn)
	        	res.push_back(word);

	        // cout<< word << " " << pttn_w << endl;
        }

        return res;
    }
};