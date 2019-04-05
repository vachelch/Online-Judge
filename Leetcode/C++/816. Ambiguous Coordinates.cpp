class Solution {
public:
	vector<string> helper(string s){
		vector<string> sector;
		int size = s.size();

		// 0XXX - 0.XXX
		// XXX0 - XXX0
		// XXXX - X.X.X.X.
		// 0XX0 - 
		if (size == 1){
			sector.push_back(s);
		}
		else if(s[0] == '0' && s.back() != '0'){
			sector.push_back("0." + s.substr(1, size-1));
		}
		else if(s[0] != '0' && s.back() == '0'){
			sector.push_back(s);
		}
		else if(s[0] != '0' && s.back() != '0'){
			for(int i=0; i< size-1; i++){
				sector.push_back(s.substr(0, i+1) + "." + s.substr(i+1, size-i));
			}
			sector.push_back(s);
		}


		return sector;
	}

    vector<string> ambiguousCoordinates(string S) {
        vector<string >res;
        int size = S.size();

        for(int i=1; i< S.size()-2; i++){
        	vector<string> fronts = helper(S.substr(1, i));
        	vector<string> behinds = helper(S.substr(i+1, size-2 - i));

        	for(auto f: fronts){
	        	for(auto b: behinds){
	        		res.push_back("("+ f + ", " + b + ")");
	        	}
	        }
        }
        
        return res;
    }
};