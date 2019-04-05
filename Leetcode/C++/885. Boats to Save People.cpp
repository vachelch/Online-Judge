bool compare(int a, int b) {
    return (a>b);
}

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0;
        sort(people.begin(), people.end(), compare);
        int i = 0, j = people.size()-1;
        
        while(i<j){
            if (people[i] + people[j] <= limit){
                i++;
                j--;
            }
            else
                i++;
            res ++;
        }
        
        if(i == j)
            res ++;
        
        return res;
    }
};