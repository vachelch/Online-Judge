class Solution {
public:
    string pushDominoes(string dominoes) {
    	int size = dominoes.size();
    	string res = "";

    	if (size == 0) return res;

    	int left[size] = {0};
    	int right[size] = {0};

    	int last = 0, sign = 0;
    	for(int i=0; i< size; i++){
    		if (dominoes[i] == '.'){
    			right[i] = sign * (i - last);
    		}
    		else if (dominoes[i] == 'R'){
    			sign = -1;
    			last = i;
    		}
    		else{
    			sign = 0;
    		}
    	}

    	sign = 0, last = 0;
    	for(int i=size - 1; i>= 0; i--){
    		if (dominoes[i] == '.'){
    			left[i] = sign * (last - i);
    		}
    		else if (dominoes[i] == 'L'){
    			sign = 1;
    			last = i;
    		}
    		else{
    			sign = 0;
    		}
    	}

    	for(int i=0; i< size; i++){
    		if(left[i] == 0 && right[i] == 0)
    			res.push_back(dominoes[i]);
    		else if (left[i] != 0 && right[i] != 0){
    			if(left[i] + right[i] < 0)
    				res.push_back('L');
	    		else if(left[i] + right[i] > 0)
	    			res.push_back('R');
	    		else
	    			res.push_back('.');
    		}
    		else{
    			if (left[i] == 0)
    				res.push_back('R');
    			else
    				res.push_back('L');
    		}
    		

    	}

    	return res;

    }
};