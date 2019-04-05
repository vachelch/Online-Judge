class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        vector<int> tmp;
        tmp.push_back(r0);
        tmp.push_back(c0);
        res.push_back(tmp);

        int r_p[] = {0, 1, 0, -1};
        int c_p[] = {1, 0, -1, 0};

        int edge = 2* max(R, C);
        int r = r0, c = c0;

        int p = 0;
        for(int d =1; d< edge; d++){
        	for (int i=0; i< d; i++){
        		r = r + r_p[p];
	        	c = c + c_p[p];

	        	if (0 <= r && r < R && 0 <= c && c < C){
	        		vector<int> cur;
	    			cur.push_back(r);
	    			cur.push_back(c);
	    			res.push_back(cur);
	    		}
        	}

        	p++;
        	if (p == 4) p = 0;

        	for (int i=0; i< d; i++){
        		r = r + r_p[p];
	        	c = c + c_p[p];

	        	if (0 <= r && r < R && 0 <= c && c < C){
	        		vector<int> cur;
	    			cur.push_back(r);
	    			cur.push_back(c);
	    			res.push_back(cur);
	    		}
        	}

        	p++;
        	if (p == 4) p = 0;
        }

        return res;
    }
};

























