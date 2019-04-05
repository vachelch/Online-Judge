#include <iostream>
#include <vector>
#include <vector>
using namespace std;

// matain a size n max heap, and pop k time
// O(n + klog(n)) time complexity, O(n) space complexity
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end(), less<int>()); // max heap
        int top;

        while(k){
        	pop_heap(nums.begin(), nums.end(), less<int>()); // max heap
	        top = nums.back();
	        nums.pop_back();
	        k--;
        }

        return top;
    }
};


// maitain a size k multiset(red black tree)
// you can get min and max value from a tree, but only get one of max or min value from a head
// O(nlog(k)) time complexity, O(k) space complexity
// !!! .end() will point to 1 step ater last element !!!
// here we can use .begin(), or prev(.end()) to get the pointer of (min value in a max_heap/ max value in a min_heap)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int, greater<int>> heap;
        
        for(auto num: nums){
            if (heap.size() < k)
                heap.insert(num);
            else{
                multiset<int, greater<int> >::iterator min_ptr = prev(heap.end());
                
                if (num > *min_ptr){
                    heap.erase(min_ptr);
                    heap.insert(num);
                }
            }
        }
        
        
        return *(prev(heap.end()));
    }
};


int main(){
	int ipt[] = {3,2,3,1,2,4,5,5,6};
	vector<int> nums(ipt, ipt + 9);
	int k = 4;

	Solution s;

	cout << s.findKthLargest(nums, k) << endl;

	return 0;
}