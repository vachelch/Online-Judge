// method 1
class Solution {
public:
     int  NumberOf1(int n) {
         int num = 0;
         int bit = 1 << 31;
          while(n!=0){
              num += ((bit & n) != 0); // the parenthesis here out of "bit & n" is very important
              n <<= 1;
          }
         return num;
     }
};

// method 2
class Solution {
public:
     int  NumberOf1(int n) {
         int num = 0;
         
          while(n){
              num ++;
              n = n & (n - 1); 
          }
         return num;
     }
};