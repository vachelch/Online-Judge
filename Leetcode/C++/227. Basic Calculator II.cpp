class Solution {
public:
    int get_number(string s, int idx, int *num){
        int size = s.size();

        // remove space
        while(idx < size && s[idx] == ' ')
            idx ++;

        int start = idx;
        while(idx < size && '0' <= s[idx] && s[idx] <= '9'){
            idx ++;
        }
        (*num) = stoi(s.substr(start, idx-start));

        // remove space
        while(idx < size && s[idx] == ' ')
            idx ++;

        return idx;
    }
    int calculate(string s) {
    	int size = s.size();

    	vector<int> num_stack;
        vector<char> oper_stack;

        int num;
        char oper;
        int res = 0;

        int i=0;
        while(1){
            i = get_number(s, i, &num);
            num_stack.push_back(num);

            if (i == size) break;

            oper = s[i++];

            if (oper == '*' || oper == '/'){
                // pop_back all '*' and '/'
                while(!oper_stack.empty() && (oper_stack.back() == '*' || oper_stack.back() == '/')){
                    char cur_oper = oper_stack.back();
                    oper_stack.pop_back();

                    int a = num_stack.back();
                    num_stack.pop_back();
                    int b = num_stack.back();
                    num_stack.pop_back();

                    if (cur_oper == '*')
                        num_stack.push_back(a*b);
                    else if (cur_oper == '/')
                        num_stack.push_back(b/a);
                }

                oper_stack.push_back(oper);
            }

            else if (oper == '+' || oper == '-'){
                // pop_back all operator
                while(!oper_stack.empty()){
                    char cur_oper = oper_stack.back();
                    oper_stack.pop_back();

                    int a = num_stack.back();
                    num_stack.pop_back();
                    int b = num_stack.back();
                    num_stack.pop_back();

                    if (cur_oper == '*')
                        num_stack.push_back(a*b);
                    else if (cur_oper == '/')
                        num_stack.push_back(b/a);
                    else if (cur_oper == '+')
                        num_stack.push_back(b+a);
                    else if (cur_oper == '-')
                        num_stack.push_back(b-a);
                }

                oper_stack.push_back(oper);
            }
        }

        // emptify oper_stack
        while(!oper_stack.empty()){
            char cur_oper = oper_stack.back();
            oper_stack.pop_back();

            int a = num_stack.back();
            num_stack.pop_back();
            int b = num_stack.back();
            num_stack.pop_back();

            if (cur_oper == '*')
                num_stack.push_back(a*b);
            else if (cur_oper == '/')
                num_stack.push_back(b/a);
            else if (cur_oper == '+')
                num_stack.push_back(b+a);
            else if (cur_oper == '-')
                num_stack.push_back(b-a);
        }
        
        return num_stack[0];
    }
};


















