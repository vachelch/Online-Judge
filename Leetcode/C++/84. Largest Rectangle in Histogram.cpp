// stack, For every item, find nearst smaller left, and smaller right  
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>left(heights.size(), 0);
        vector<int>right(heights.size(), 0);
        vector<pair<int, int>> stack;
        
        stack.push_back(make_pair(-1, -1));
        
        for(int i=0; i< heights.size(); i++){
            while(heights[i] <= stack.back().second)
                stack.pop_back();
            
            left[i] = stack.back().first;
            stack.push_back(make_pair(i, heights[i]));
        }
        
        stack.clear();
        stack.push_back(make_pair(heights.size(), -1));
        for(int i=heights.size() - 1; i>= 0; i--){
            while(heights[i] <= stack.back().second)
                stack.pop_back();
            
            right[i] = stack.back().first;
            stack.push_back(make_pair(i, heights[i]));
        }
        
        int res = 0;
        for (int i=0; i< heights.size(); i++){
            res = max(heights[i] * (right[i] - left[i] - 1), res);
        }
        
        return res;
    }
};