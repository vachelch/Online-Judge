class Solution {
public:
    int Add(int num1, int num2)
    {
        int sum = num1 ^ num2;
        int add_one = (num1 & num2) << 1;
            
        while(add_one){
            int tmp = sum ^ add_one;
            add_one = (sum & add_one) << 1;
            sum = tmp;
        }
        
        return sum;
    }
};