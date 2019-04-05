// 1. binary search
class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> vec;
    int bin_search(vector<int>& vec, int num){
        int l = 0;
        int r = vec.size() - 1;
        if (r == 0){
            if (vec[0] >= num) return 0;
            else return 1;
        }
        while(l < r){
            int mid = (l + r) /2;
            if (vec[mid] == num)
                return mid;
            else if(vec[mid] > num)
                r = mid;
            else 
                l = mid + 1;
        }
        
        return l;
        
    }
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (vec.empty() || num > vec.back()) vec.push_back(num);
        else{
            int idx = bin_search(vec, num);
            vec.insert(vec.begin()+idx, num);
        }
    }
    
    double findMedian() {
        if (vec.empty()) return 0;
        if (vec.size() % 2) return vec[vec.size() / 2];
        else return (vec[vec.size() / 2] + vec[vec.size() / 2 - 1])*1.0 / 2; 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */




// 2. max_heap, min_ehap
