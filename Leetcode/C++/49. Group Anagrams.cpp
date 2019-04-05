class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<int> > table;

        for(int i=0; i< strs.size(); i++){
        	map<char, int> dict;
        	string word = strs[i];
        	for(auto c: word)
        		dict[c] ++;

        	if(table.find(dict) != table.end())
        		table[dict].push_back(i);
        	else{
        		vector<int> v;
        		v.push_back(i);
        		table[dict] = v;
        	}

        }

        vector<vector<string>> res;
        for(auto it: table){
        	vector<string> words;
        	for(auto idx: it.second){
        		words.push_back(strs[idx]);
        	}
        	res.push_back(words);
        }

        return 0;
        
    }
};