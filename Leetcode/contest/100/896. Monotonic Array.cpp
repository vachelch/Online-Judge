class Solution {
public:
    bool isMonotonic(vector<int>& A) {
  		if (A.size() <= 2) 
  			return true;

  		bool ascend = true, descend = true;
  		for(int i=1; i< A.size(); i++){
  			if (A[i] < A[i-1]){
  				ascend = false;
  				break;
  			}
  		}

  		for(int i=1; i< A.size(); i++){
  			if (A[i] > A[i-1]){
  				descend = false;
  				break;
  			}
  		}

  		return (ascend || descend);
    }
};