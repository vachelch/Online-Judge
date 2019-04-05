class Solution {
public:
    int bin_search_rotate(vector<int>& rotateArray, int l, int r){
        while(l < r){
            int mid = l + (r-l)/2;
            if (rotateArray[l] < rotateArray[r]) return rotateArray[l];
            else if(rotateArray[l] > rotateArray[r]){
                if (rotateArray[mid] >= rotateArray[l])
                    l = mid + 1;
                else
                    r = mid;
            }
            else{
                if (rotateArray[mid] > rotateArray[l])
                    l = mid + 1;
                else if (rotateArray[mid] < rotateArray[l])
                    r = mid;
                else
                    ++l;
            }
        }
        return rotateArray[l];
    }
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty()) return 0;
        
        return bin_search_rotate(rotateArray, 0, rotateArray.size()-1);
    }
};




class Solution {
public:
    int linear_search(vector<int> &rotateArray, int l, int r){
        int mn_idx = l;
        for(int i=l+1; i<= r; i++){
            if(rotateArray[i] < rotateArray[mn_idx]){
                mn_idx = i;
            }
        }
        return mn_idx;
    }
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 0) return 0;
        int l = 0, r = rotateArray.size()-1;
        
        while(l+1 < r){
            int mid = l + (r - l) /2;
            if (rotateArray[mid] > rotateArray[l]){
                l = mid;
            }
            else if(rotateArray[mid] < rotateArray[l])
                r = mid;
            else{
                if (rotateArray[mid] > rotateArray[r])
                    l = mid;
                else if (rotateArray[mid] < rotateArray[r])
                    r =  mid;
                else
                    r = linear_search(rotateArray, l, r);
            }
        }
        
        return rotateArray[r];
    }
};