bool cmp(pair<char, int>& a, pair<char, int>& b){
	return a.second > b.second;
}

class Solution {
public:
    string reorganizeString(string S) {
    	if (S == "") return S;

    	int S_arr[26] = {0};
        
        for(auto s: S)
        	S_arr[s - 'a'] ++;

        vector<pair<char, int>> chrs;
        for(int i=0; i< 26; i++){
        	if (S_arr[i] != 0)
        		chrs.push_back(make_pair('a' + i, S_arr[i]));
        }

        sort(chrs.begin(), chrs.end(), cmp);
        string s_sort = "";
        for(auto chr: chrs){
        	while(chr.second--){
        		s_sort.push_back(chr.first);
        	}
        }
			
		int l = 0;
		int r = s_sort.size() / 2;
		string res = "";

		if (s_sort.size() % 2 == 0){
			if (s_sort[r] == s_sort[0]) return "";

			int size = s_sort.size() / 2;
			while(size--){
				res.push_back(s_sort[l++]);
				res.push_back(s_sort[r++]);
			}
		}
		else{
			r++;
			if (r < s_sort.size() && s_sort[r] == s_sort[0]) return "";

			int size = s_sort.size() / 2;
			while(size--){
				res.push_back(s_sort[l++]);
				res.push_back(s_sort[r++]);
			}
			res.push_back(s_sort[l]);
		}

		return res;
    }
};