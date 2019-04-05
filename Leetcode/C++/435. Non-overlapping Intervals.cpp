/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(Interval a, Interval b){
    if (a.end <= b.end)
        return true;
    else
        return false;
}
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        
        if (intervals.size() == 0) return 0;
        int sm = 1;
        int end = intervals[0].end;
        for(int i=1; i< intervals.size(); i++){
            if (intervals[i].start >= end){
                sm ++;
                end = intervals[i].end;
            }
        }
        
        return intervals.size() - sm;
    }
};