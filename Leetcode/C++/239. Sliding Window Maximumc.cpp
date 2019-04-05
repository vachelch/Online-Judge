class Solution {
public:
    int bin_search(deque<int>& sorted_queue, int num){
        int l = 0;
        int r = sorted_queue.size() - 1;

        if (r == 0){
            if (num >= sorted_queue[0]) return 1;
            else return 0;
        }

        while(l < r){
            int mid = (l + r) / 2;
            if (sorted_queue[mid] == num)
                return mid;
            else if (sorted_queue[mid] > num)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
    void Insert(deque<int>& sorted_queue, int num){
        if (sorted_queue.empty() || num >= sorted_queue.back()){
            sorted_queue.push_back(num);
        }

        else{
            int idx = bin_search(sorted_queue, num);
            sorted_queue.insert(sorted_queue.begin()+idx, num);
        }
    }

    void Pop(deque<int>& sorted_queue, int num){
        int idx = bin_search(sorted_queue, num);
        sorted_queue.erase(sorted_queue.begin()+idx);
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // idx == 0
        deque<int> sorted_queue;

        for(int i=0; i< k; i++)
            Insert(sorted_queue, nums[i]);

        vector<int> res;
        if (nums.empty()) return res;
        res.push_back(sorted_queue.back());

        for(int i=1; i< nums.size() - k + 1; i++){
            Pop(sorted_queue, nums[i-1]);
            Insert(sorted_queue, nums[i+k-1]);

            res.push_back(sorted_queue.back());
        }   

        return res;
    }
};
