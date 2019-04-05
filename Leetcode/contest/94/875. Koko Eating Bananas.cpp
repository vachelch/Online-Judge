class Solution {
public:
	int check(vector<int>& piles, int middle, int H){
		int sm = 0;
		for(int i=0; i< piles.size(); i++){
			sm += piles[i] / middle + (piles[i] % middle > 0);
		}

		return (sm <= H);
	}
    int minEatingSpeed(vector<int>& piles, int H) {
        int right = *max_element(piles.begin(), piles.end());
        int left = 1;
        int middle, res;

        while (left <= right){
        	middle = (right + left) / 2;
        	if (check(piles, middle, H)){
        		res = middle;
        		right = middle - 1;
        	}
        	else{
        		left = middle + 1;
        	}
        }

        return res;
    }
};