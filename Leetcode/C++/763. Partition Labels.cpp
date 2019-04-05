class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char, int> store;
        for (int i=0; i< S.size(); i++){
        	if (store.find(S[i]) == store.end())
        		store[S[i]] = 1;
        	else
        		store[S[i]] += 1;
        }

        vector<int> res;
        map<char, int> cur;
        int start = -1;
        for(int i=0; i< S.size(); i++){
        	if (cur.find(S[i]) == cur.end())
        		cur[S[i]] = 1;
        	else
        		cur[S[i]] += 1;

        	// check whether this parts can be partitioned
        	int partition = 1;
        	// the next code row can be substituted to be
        	// for(map<char, int>::iterator it = cur.begin(); it != cur.end(); ++it)
        	// it->first, it->second
        	for (auto const & element : cur){
        		char key = element.first;
        		char val = element.second;

        		if (store[key] == val){
        			cur.erase(key);
        		}
        		else{
        			partition = 0;
        			break;
        		}
        	}

        	if (partition){
        		res.push_back(i - start);
        		start = i;
        	}
        }

        return res;
    }
};