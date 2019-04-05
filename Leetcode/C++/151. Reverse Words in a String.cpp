class Solution {
public:
    void reverse(string &s, int l, int r){
        while(l < r){
            // swap(s, l, r);
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            
            ++l;
            --r;
        }
    }
    void reverseWords(string &s) {
        if (s.size() == 0) return ;
        
        // reverse the sentence
        int i = 0;
        while(i < s.size() && s[i] == ' '){
            i ++;
        }
        reverse(s, i, s.size()-1);

        // jump leading spaces
        while(i < s.size() && s[i] == ' '){
            i ++;
        }

        int start = i;
        while(i < s.size()){
            if (s[i] == ' '){
                reverse(s, start, i-1);
                while(i < s.size() && s[i] == ' '){
                    i ++;
                }
                start = i;
            }

            if (i == s.size()-1)
                reverse(s, start, i);

            i++;
        }

        // remove repeated space
        int size = s.size();
        int left_move_step = 0;

        i = 0;
        bool last_is_space = true;
        int reduce_cnt = 0;
        while(i < size){
            if (s[i] == ' '){
                if (last_is_space){
                    left_move_step ++;
                }
                else{
                    last_is_space = true; 
                    s[i - left_move_step] = s[i];
                }
            }
            else{
                last_is_space = false;
                s[i - left_move_step] = s[i];
            }

            i++;
        }

        s = s.substr(0, size - left_move_step);
    }
};