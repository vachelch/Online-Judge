class Solution {
public:
    int maxArea(vector<int>& height) {
    	int l=height.size();
    	int mx = 0;
    	int left = 0, right = l-1;

        while(left < right){
        	if(height[left] > height[right]){
        		mx = max(mx, height[right]*(right-left));
        		right --;
        	}
        	else{
        		mx = max(mx, height[left]*(right-left));
        		left ++;
        	}
 
        }

        return mx;
    }
};




// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//     	int l=height.size();
//     	int volume;
//     	int mx = 0;

//         for(int i=0; i<l; i++){
//         	int mx_border = height[l-1]-1;
//         	for(int j=l-1; j>i; j--){
// 	        	if(height[j] > mx_border){
// 	        		mx_border = height[j];
// 	        		volume = (j-i) * min(height[i], mx_border);
// 					mx = max(volume, mx);
// 				}
//         	}
//         }

//         return mx;
//     }
// };