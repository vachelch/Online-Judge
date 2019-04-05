// Be careful to the memeory limit 'length'
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if (str == NULL || length <= 0) return ;
        
        int cnt = 0;
        int i = 0;
        while(str[i] != '\0'){
            if(str[i] == ' ') cnt ++;
            i++;
        }
        
        int newlen = i + cnt*2;
        if (newlen >= length) return;
        str[newlen] = '\0';
        
        for(int j=i-1; j>=0; j--){
            if (str[j] == ' '){
                str[--newlen] = '0';
                str[--newlen] = '2';
                str[--newlen] = '%';
            }
            else{
                str[--newlen] = str[j];
            }
        }
        
        return ;
	}
};