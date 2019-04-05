class Solution {
public:
    bool match_in(char* str, int s, char* pattern, int p){
        if(s == strlen(str) && p == strlen(pattern))
            return true;
        
        while(s < strlen(str) && p < strlen(pattern)){
            // case 1: next char is '*';
            if(p < strlen(pattern)-1 && pattern[p+1] == '*'){
                if (str[s] != pattern[p] && pattern[p] != '.') p += 2;
                else return match_in(str, s, pattern, p+2) || match_in(str, s+1, pattern, p) || match_in(str, s+1, pattern, p+2);
            }
            // case 2: next char is not '*';
            else{
                if (str[s] == pattern[p] || pattern[p] == '.') s++, p++;
                else return false;
            }
        }
        
        // match(~, ~)
        if(s == strlen(str) && p == strlen(pattern)) return true;
        // match(~ | ~x*)
        if (s == strlen(str) && p == strlen(pattern)-2 && pattern[p+1] == '*') return true;

        return false;
    }
    bool match(char* str, char* pattern)
    {   
        return match_in(str, 0, pattern, 0);
    }
};


class Solution {
public:
    bool dfs(char* str, char* pattern, int s, int p){
        if(s == strlen(str) && p == strlen(pattern)) return true;
        
        while(s < strlen(str) && p < strlen(pattern)-1){
            if (pattern[p+1] == '*'){
                if(str[s] != pattern[p] && pattern[p] != '.') p += 2;
                else return dfs(str, pattern, s, p+2) || dfs(str, pattern,s+1, p) || dfs(str, pattern, s+1, p+2);
            }
            else{
                if (str[s] != pattern[p] && pattern[p] != '.') return false;
                s++;
                p++;
            }
        }
        
        // p reach end
        if (p == strlen(pattern) -1){
            if(s == strlen(str)-1 && (str[s] == pattern[p] || pattern[p] == '.')) return true;
        }
        // s reach end
        else{
            if(pattern[p+1] == '*') return dfs(str, pattern, s, p+2);
        }
        return false;
    }
    bool match(char* str, char* pattern)
    {
        return dfs(str, pattern, 0, 0);
    }
};