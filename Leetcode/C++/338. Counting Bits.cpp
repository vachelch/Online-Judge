class Solution {
public:
    vector<int> countBits(int num) {
    	vector<int> res(1, 0);
    	if (num == 0) return res;
    	res.push_back(1);
    	if (num == 1)
    		return res;
    	int i = 4;
    	while(i <= num + 1){
        	for(int j=i / 4; j < i / 2; j++){
    			res.push_back(res[j]);
        	}
        	for(int j=i / 2; j < 3*i / 4; j++){
    			res.push_back(res[j] + 1);
        	}
        	i *= 2;
    	}

    	for(int j=i / 4; j < i / 2 && j + i/4 <= num; j++){
			res.push_back(res[j]);
        }
        for(int j = i / 2; j < 3*i/4 && j + i/4 <= num; j++){
			res.push_back(res[j] + 1);
        }

        return res;
    }
};