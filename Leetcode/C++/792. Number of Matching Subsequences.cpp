class Solution {
public:
    int bin_search(vector<int>& vec, int idx){
        int l = 0, r = vec.size()-1;
        int mid;
        
        while(l < r){
            mid = (l + r) / 2;
            if (vec[mid] == idx)
                return vec[mid];
            else if (vec[mid] < idx)
                l = mid + 1;
            else
                r = mid;
        }
        
        if (vec[l] < idx)
            return -1;
        else
            return vec[l];
    }
    int numMatchingSubseq(string S, vector<string>& words) {
        int res = 0;
        map<char, vector<int>>indexs;
        for(int i=0; i< S.size(); i++){
            if (indexs.find(S[i]) != indexs.end())
                indexs[S[i]].push_back(i);
            else{
                vector<int> v(1, i);
                indexs[S[i]] = v;
            }    
        }
            
        for(auto word : words){
            int start = 0;
            for(int i=0; i< word.size(); i++){
                if (indexs.find(word[i]) == indexs.end()){
                    start = -1;
                    break;   
                }
                start = bin_search(indexs[word[i]], start);
                if (start == -1)
                    break;
                start ++;
            }
            if (start != -1){
                res ++;
            }
                
        }
        
        return res;
    }
};