class Solution {
public:
    string intToRoman(int num) {
        string ones_[] = {"I", "X", "C"}; // 1, 10, 100
        string fives_[] = {"V", "L", "D"}; // 5, 50, 500
        string tens_[] = {"X", "C", "M"}; // 10, 100, 1000
        string res = "";
        
        // 1000
        while (num >= 1000){
            res += "M";
            num -= 1000;
        }

        for(int i=2; i>= 0; i--){
            int base = pow(10, i);
            // 9
            if (num >= base*9){
                res = res + ones_[i] + tens_[i];
                num -= base*9;
            }
            // 5
            else if(num >= base*5){
                res = res + fives_[i];
                num -= base*5;
            }
            // 4
            else if(num >= base*4){
                res = res + ones_[i] + fives_[i];
                num -= base * 4;
            }
            // 1
            while(num >= base){
                res += ones_[i];
                num -= base;
            }
        }

        return res;
    }
};