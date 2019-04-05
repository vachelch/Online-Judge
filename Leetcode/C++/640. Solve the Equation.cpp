#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string solveEquation(string equation) {
    	int start=0;
    	int sign = 1;
    	int x = 0;
    	int num = 0;
        int idx = 0;

        if (equation[0] == '-'){
            sign = -1;
            idx = 1;
            start = 1;
        }
        for(; idx< equation.size(); idx++){
        	if (equation[idx] == '+' || equation[idx] == '-' || equation[idx] == '='){
        		int len = idx - start;
        		if (equation[idx-1] == 'x'){
        			len --;
                    if (len == 0)
                        x += sign;
                    else
                        x += sign * stoi(equation.substr(start, len));
        		}
        		else{
        			num += sign * stoi(equation.substr(start, len));
        		}

        		if(equation[idx] == '+')
        			sign = 1;
        		else if (equation[idx] == '-')
        			sign = -1;
                else
                    break;

        		start = idx+1;
        	}

        }

        start = ++idx ;
        sign = -1;

        if (equation[idx] == '-'){
            sign = 1;
            start = ++ idx;
        }

        for(; idx< equation.size(); idx++){
        	if (equation[idx] == '+' || equation[idx] == '-'){
        		int len = idx - start;
        		if (equation[idx-1] == 'x'){
        			len --;
                    if (len == 0)
                        x += sign;
                    else
                        x += sign * stoi(equation.substr(start, len));
        		}
        		else{
        			num += sign * stoi(equation.substr(start, len));
        		}

        		if(equation[idx] == '+')
        			sign = -1;
        		else
        			sign = 1;
        		
        		start = idx+1;
        	}
        }

        int len = idx - start;

        if (equation[idx-1] == 'x'){
            len --;
            if (len == 0)
                x += sign;
            else
                x += sign * stoi(equation.substr(start, len));
        }
        else{
            num += sign * stoi(equation.substr(start, len));
        }

        if (x == 0 && num == 0)
        	return  "Infinite solutions";
        else if(x == 0 && num != 0)
        	return "No solution";
        else
        	return "x=" + to_string(-1 * num / x);
    }
};


int main(){
	Solution s;
	string equation = "x=x";
	cout << s.solveEquation(equation) << endl;;

	return 0;
}




