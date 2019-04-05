#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <set>
using namespace std;

class Solution {
public:
	int visited[10000];
	int distance[10000];
	set<int> deads_set;
	deque<int> q;

	vector<int> adjacents(int n){
		vector<int> adjs;
		string str_n = to_string(n);

		int size = str_n.size();
		for(int i=0; i< 4-size; i++)
			str_n = "0" + str_n;

		for(int i=0; i< 4; i++){
			if(str_n[i] == '0'){
				string tmp = str_n;

				tmp[i] = '1';
				adjs.push_back(stoi(tmp));
				tmp[i] = '9';
				adjs.push_back(stoi(tmp));
			}
			else if(str_n[i] == '9'){
				string tmp = str_n;

				tmp[i] = '0';
				adjs.push_back(stoi(tmp));
				tmp[i] = '8';
				adjs.push_back(stoi(tmp));
			}
			else{
				string tmp = str_n;

				tmp[i] = tmp[i] - 1;
				adjs.push_back(stoi(tmp));
				tmp[i] = tmp[i] + 2;
				adjs.push_back(stoi(tmp));
			}
		}

		return adjs;
	}

    int openLock(vector<string>& deadends, string target) {
        memset(visited, 0, 10000*sizeof(int));
        memset(distance, -1, 10000*sizeof(int));

        for(auto dead: deadends)
        	deads_set.insert(stoi(dead));

        if (deads_set.find(0) == deads_set.end()){
        	visited[0] = 1;
	        distance[0] = 0;
	        q.push_back(0);
        }
        
        int tar = stoi(target);
        // dfs
        while(!q.empty()){
        	int idx = q.front();

        	if (idx == tar)
        		break;

        	q.pop_front();
        	int dis = distance[idx];

        	vector<int> adjs = 	adjacents(idx);
	    	for(auto adj: adjs){
	    		if (!visited[adj] && (deads_set.find(adj) == deads_set.end())){
	    			visited[adj] = 1;
	    			distance[adj] = dis+1;
	    			q.push_back(adj);
	    		}
	    	}
        	
        }
        
        return distance[stoi(target)];
    }
};



int main(){
	string str[] = {"0000"};
	// string str[] = {"8887","8889","8878","8898","8788","8988","7888","9888"};
	vector<string> deadends(str, str + 1);
	string target = "8888";

	Solution s;
	cout << s.openLock(deadends, target) << endl;
	return 0;
}

















