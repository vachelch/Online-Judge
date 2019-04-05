// greedy
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
            
        int last_height = 0;
        int last_idx = 0;
        int volume = 0;
        int sum = 0;
        for(int i=0; i< height.size(); i++){
            if (height[i] >= last_height){
                volume += (i-1 - last_idx + 1) * last_height;
                last_idx = i;
                last_height = height[i];
            }
            sum += height[i];
        }
        sum -= last_height;
        
        // last_idx to end volumn;
        int end = last_idx;
        last_height = 0;
        last_idx = height.size();
        for(int i = height.size() -1; i>= end; i--){
            if (height[i] >= last_height){
                volume += (last_idx - i) * last_height;
                last_idx = i;
                last_height = height[i];
            }
        }
        return volume - sum;
    }
};