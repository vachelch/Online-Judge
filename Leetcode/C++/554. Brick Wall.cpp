class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        map<int, int> dict;
        int mx = 0;
        for(int i=0; i<wall.size(); i++){
            dict[wall[i][0]] ++;
            if (wall[i].size() > 1)
                mx = max(dict[wall[i][0]], mx);
            for(int j=1; j<wall[i].size()-1; j++){
                wall[i][j] += wall[i][j-1];
                dict[wall[i][j]] ++;
                mx = max(dict[wall[i][j]], mx);
            }
        }
            
        return wall.size() - mx;
    }
};