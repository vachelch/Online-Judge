// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int a = rand7();
        int b = rand7();
        int c = (a-1) * 7 + b;
        return (c <=40)? ((c-1) % 10) + 1 : rand10();
        // or, return (c <=40)? (c % 10) + 1 : rand10();
    }
}; 