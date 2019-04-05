// hash (slower)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        map<int, int> calendar;
        vector<int> res(temperatures.size(), 30000);

        for(int i=temperatures.size()-1; i >= 0; i--){
        	calendar[temperatures[i]] = i;
        	for(int j= temperatures[i]+1; j<= 100; j++){
        		if (calendar.find(j) != calendar.end()){
        			res[i] = min(calendar[j] - i, res[i]);
        		}
        	}
        	if (res[i] == 30000) res[i] = 0;
        }

        return res;
    }
};



// stack (faster)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        deque<pair<int, int>> q;

        for(int i=temperatures.size()-1; i>=0; i--){
        	while(1){
        		if (q.empty()){
        			res[i] = 0;
        			q.push_back(make_pair(temperatures[i], i));
        			break;
        		}
        		else if(q.back().first <= temperatures[i])
        			q.pop_back();
        		else{
        			res[i] = q.back().second - i;
        			q.push_back(make_pair(temperatures[i], i));
        			break;
        		}
        	}
        }

        return res;
    }
};



















