bool compare(pair<string, int>& a, pair<string, int>& b){
	if (a.second < b.second || (a.second == b.second && a.first > b.first))
		return true;
	else
		return false;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> dict;

        for(auto word: words)
        	dict[word] ++;

        vector<pair<string, int>> words_cnt;
        for(auto it: dict)
         	words_cnt.push_back(make_pair(it.first, it.second));

        make_heap(words_cnt.begin(), words_cnt.end(), compare);

        vector<string> res;

        while(k--){
        	res.push_back(words_cnt.front().first);
        	pop_heap(words_cnt.begin(), words_cnt.end(), compare);
        	words_cnt.pop_back();
        }

        return res;
    }
};



