// maitain median and cnt, O(n)
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) return 0;
        
        int median = numbers[0], cnt = 1;
        for(auto num: numbers){
            if (num == median){
                cnt ++;
            }
            else{
                if (cnt == 0){
                    median = num;
                    cnt = 1;
                }
                else{
                    cnt --;
                }
            }
        }
        
        if (cnt == 0) return 0;
        int median_cnt = 0;
        for(auto num: numbers){
            median_cnt += (num == median);
        }
        
        return (2*median_cnt > numbers.size())? median: 0;
    }
};


// Partition, average O(n)
class Solution {
public:
    int Partition(vector<int>& numbers, int l, int r){
        int idx = -1;
        for(int i=l; i<= r; i++){
            if (numbers[i] <= numbers[r]){
                ++ idx;
                // swap(numbers, i, idx);
                int tmp = numbers[i];
                numbers[i] = numbers[idx];
                numbers[idx] = tmp;
            }
        }

        return idx;
    }

    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) return 0;
        int median_idx = numbers.size() / 2;
        int l = 0, r = numbers.size() - 1;

        int pivot = Partition(numbers, l, r);    

        while(pivot != median_idx){
            if(pivot < median_idx)
                l = pivot+1;
            else
                r = pivot-1;

            pivot = Partition(numbers, l, r);
        }
        
        
        int median =  numbers[pivot];
        int median_cnt = 0;
        for(auto num: numbers){
            median_cnt += (num == median);
        }
        
        return (2*median_cnt > numbers.size())? median: 0;
    }
};