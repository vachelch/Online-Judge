class Solution {
public:
    int search(vector<int>& nums, int target) {
    	l = len(nums)
    	left = 0
    	right = l-1

    	while left <= right:
	        middle = (left+right)//2
	        if target == nums[middle]:
	        	return middle
	        if nums[left] < nums[middle]:
	        	right = middle - 1
	        	while left<= right:
	        		middle = (left+right)//2
	        		if nums[middle] == target: return middle
	        		elif nums[middle] < target:
	        			left = middle + 1
	        		else
	        			right = middle - 1
	        else:
	        	left = middle + 1

	    return -1
    }
};