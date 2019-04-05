class Solution {
public:
	int right; // right == INT_MAX / nums[right] > target

	int bin_search(vector<int>& nums, int target, int l, int r){
		while(l < r){
			int mid = (l + r) /2;
			if (nums[mid] == target)
				r = mid;
			else if (nums[mid] < target)
				l = mid + 1;
			else{
				right = mid;
				r = mid - 1;
			}
		}

		if (nums[l] == target)
			return l;
		return -1;
	}

	int bin_search2(vector<int>& nums, int target, int l, int r){
		while(l < r){
			int mid = (l + r) /2;
			if (nums[mid] == target)
				l = mid+1;
			else{
				r = mid - 1;
			}
		}
		if (nums[l] == target) return l;
		return l - 1;
	}

    vector<int> searchRange(vector<int>& nums, int target) {
        right = INT_MAX;
        int size = nums.size();
        if (size == 0) return vector<int>(2, -1);

        int l = bin_search(nums, target, 0, nums.size()-1);
        int r;
        // no right (target is the largest number, or can't find target)
        if (l == -1)
        	r = l;
        else{
        	r = bin_search2(nums, target, l, min(right, size-1));
        }

        int ans[2] = {l, r};
        vector<int> res(ans, ans+2);
        return res;
    }
};