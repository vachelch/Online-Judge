class Solution {
public:
    bool rotateString(string A, string B) {
    	string s1;
    	string s2;
    	if (A == B) return true
        for(int i=0; i<A.size(); i++){
        	s1.assign(A.begin(), A.begin() + i);
        	s2.assign(A.begin()+i, A.end());

        	if (s2 + s1 == B)
        		return true;
        }

        return false;
    }
};