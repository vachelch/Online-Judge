bool compare(pair<int, int> & a, pair<int, int> & b){
    if (a.first < b.first || (a.first == b.first && a.second > b.second)) return true;
    else
        return false;
}
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end(), compare);
        
        int res = 0;
        for(int i=0; i< points.size(); ){
            int bound = points[i].second;
            int j=i+1;
            for(; j< points.size(); j++){
                if (points[j].first > bound){
                    i = j;
                    break;
                } 
                bound = min(bound, points[j].second);
            }
            res ++;
            if (j == points.size())
                break;
        }
        
        return res;
    }
};