// O(n) time complexity, O(n) spcace complexity
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> vec;
        for(auto num: array)
            if(num % 2) vec.push_back(num);
        
        for(auto num: array)
            if (num % 2 == 0) vec.push_back(num);
        
        for(int i=0; i< vec.size(); i++)
            array[i] = vec[i];
        
        return ;
    }
};

// bubble sort
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        for(int i=0; i< array.size()-1; i++){
            for(int j=array.size()-1; j > i; j--){
                if (array[j]% 2 != 0 && array[j-1]% 2 == 0){
                    // swap
                    int tmp = array[j];
                    array[j] = array[j-1];
                    array[j-1] = tmp;
                }
            }
        }
    }
};
