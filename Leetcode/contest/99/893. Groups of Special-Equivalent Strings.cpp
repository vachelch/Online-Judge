class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        vector<pair<map<char, int>, map<char, int>>> A_dict;

        for(int i=0; i< A.size(); i++){
        	map<char, int> odd_dict;
        	map<char, int> even_dict;
        	for(int j=0; j< A[i].size(); j+= 2){
        		even_dict[A[i][j]] ++;
        	}

        	for(int j=1; j< A[i].size(); j+= 2){
        		odd_dict[A[i][j]] ++;
        	}	
        	A_dict.push_back(make_pair(even_dict, odd_dict));
        }

        set<pair<map<char, int>, map<char, int>>> A_set;
        for(int i=0; i< A.size(); i++){
        	A_set.insert(A_dict[i]);
        }

        int res = 0;
        for(auto item: A_set)
        	res ++;
       	
       	return res;
    }
};