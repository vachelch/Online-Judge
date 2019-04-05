// every number val could stay in numbers[val], if no repeatition
// time O(n), space O(1)
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        for(int i=0; i< length; i++){
            int val = numbers[i];
            if (val != i){
                if (numbers[val] == val){
                    * duplication = val;
                    return true;
                }
                else{
                    // swap to it's position
                    numbers[i] = numbers[val];
                    numbers[val] = val;
                }
            }
        }
        
        return false;
    }
};