class Solution {
public:
    bool detectCapitalUse(string word) {
        if ('a' <= word[0] && word[0] <= 'z'){
            for(int i=1; i< word.size(); i++){
                if (!('a' <= word[i] && word[i] <= 'z'))
                    return false;
            }
            return true;
        }
        else{
            if(word.size() == 1) return true;
            else if('a' <= word[1] && word[1] <= 'z'){
                for(int i=2; i < word.size(); i++){
                    if (!('a' <= word[i] && word[i] <= 'z'))
                        return false;
                }
                return true;
            }
            else{
                for(int i=2; i < word.size(); i++){
                    if (!('A' <= word[i] && word[i] <= 'Z'))
                        return false;
                }
                return true;
            }
        }
    }
};