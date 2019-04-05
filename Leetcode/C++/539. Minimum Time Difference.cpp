bool compare(pair<int, int> & a, pair<int, int> & b){
    if (a.first < b.first || (a.first == b.first && a.second < b.second))
        return true;
    else
        return false;
}

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<pair<int, int>> timeNum;
        for(int i=0; i< timePoints.size(); i++){
            int h = stoi(timePoints[i].substr(0, 2));
            int m = stoi(timePoints[i].substr(3, 2));
            
            timeNum.push_back(pair<int, int>(h, m));
        }
        
        sort(timeNum.begin(), timeNum.end(), compare);
        
        int mn = 24 * 60;
        timeNum.push_back(make_pair(timeNum[0].first + 24, timeNum[0].second));
        for(int i=1; i< timeNum.size(); i++){
            int cur = (timeNum[i].first - timeNum[i-1].first) * 60 + (timeNum[i].second - timeNum[i-1].second);
            mn = min(cur, mn);
        }
        
        return mn;
    }
};