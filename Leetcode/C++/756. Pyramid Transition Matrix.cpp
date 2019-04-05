class Solution {
public:
	map<string, vector<string> > dict;

	bool check(string bottom){
		if (bottom.size() == 1) return true;

		//whether bottom have upper layer
		for(int i=1; i< bottom.size(); i++){
			string pre = bottom.substr(i-1,2);

			if(dict.find(pre) == dict.end())
				return false;
		}

		vector<string> upper_layer;
		getList(bottom, 1, "", upper_layer);

		for(int i=0; i< upper_layer.size(); i++)
			if(check(upper_layer[i]))
				return true;

		return false;


	}
	void getList(string bottom, int idx, string cur, vector<string>& upper_layer){
		if (idx == bottom.size()){
			upper_layer.push_back(cur);
			return ;
		}
		string pre = bottom.substr(idx-1, 2);
		for(auto it: dict[pre]){
			cur += it;
			getList(bottom, idx+1, cur, upper_layer);
			cur.pop_back();
		}
	}
    bool pyramidTransition(string bottom, vector<string>& allowed) {
    	// dict
        for(int i=0; i< allowed.size(); i++){
        	string pre = allowed[i].substr(0, 2);
        	string back = string(1, allowed[i].back());
        	if(dict.find(pre) != dict.end())
        		dict[pre].push_back(back);
        	else
        		dict[pre] = vector<string> (1, back);
        }

        return check(bottom);
    }
};