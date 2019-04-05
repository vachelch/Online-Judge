bool myfunc(const pair<int, int> &a, const pair<int, int> &b){
    return (a.first > b.first) || ((a.first == b.first) && (a.second < b.second));
}

class Solution {
public: 
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), myfunc);
        vector<pair<int, int>> res;
        for(vector<pair<int, int>>::iterator it = people.begin(); it != people.end(); it ++){
        	res.insert(res.begin() + it->second, pair<int , int> (it->first, it->second));
        }

        return res;
    }
};