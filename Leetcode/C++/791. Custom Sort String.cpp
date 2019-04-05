class Solution {
public:
    string customSortString(string S, string T) {
    	map<char, int> s_dict;
        for (int i =0; i < T.size(); i++){
        	if (s_dict.find(T[i]) == s_dict.end())
        		s_dict[T[i]] = 1;
        	else
        		s_dict[T[i]] ++;
        }

        string res;
        for(int i=0; i< S.size(); i++){
        	if (s_dict.find(S[i]) != s_dict.end()){
        		for(int j=0; j< s_dict[S[i]]; j++)
        			res += S[i];
        		s_dict.erase(S[i]);
        	}
        }

        for(const auto & it: s_dict){
        	for(int i=0; i< it.second; i++)
        		res += it.first;
        }

        return res;
    }
};

