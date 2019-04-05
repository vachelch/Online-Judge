#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int xs[] = {p1[0], p2[0], p3[0], p4[0]};
        int ys[] = {p1[1], p2[1], p3[1], p4[1]};

        float x = 0, y = 0;
        int same = true;
        for(int i=0; i< 4; i++){
        	x += xs[i] * 1.0 / 4;
        	y += ys[i] * 1.0 / 4;

        	if (xs[0] != xs[i])
        		same = false;
        }

        if (same)
        	return false;

        bool equal_cross = true;
        float cross_square = (x - xs[0])*(x - xs[0]) + (y - ys[0])*(y - ys[0]);
        for(int i=1; i< 4; i++){
        	if ((x - xs[i])*(x - xs[i]) + (y - ys[i])*(y - ys[i]) != cross_square)
        		equal_cross = false;
        }

        if (equal_cross){

        	int a_x, a_y, b_x, b_y, c_x, c_y;
	        // pick three point randomly, find cross, check orthogonal attribute.
	        if ((p3[0] + p1[0] == 2 * x) && (p3[1] + p1[1] == 2 * y)){
	        	a_x = p3[0], a_y = p3[1];
	        	b_x = p1[0], b_y = p1[1];
	        	c_x = p2[0], c_y = p2[1];

	        }
	        else if ((p3[0] + p2[0] == 2*x) && (p3[1] + p2[1] == 2 * y)){
	        	a_x = p3[0], a_y = p3[1];
	        	b_x = p2[0], b_y = p2[1];
	        	c_x = p1[0], c_y = p1[1];

	        }
	        else{
	        	a_x = p1[0], a_y = p1[1];
	        	b_x = p2[0], b_y = p2[1];
	        	c_x = p3[0], c_y = p3[1];

	        }

	        float x1 = a_x - b_x, y1 = a_y - b_y;
	        float x2 = c_x - x, y2 = c_y - y;


	        return (x1* x2 + y1 * y2 == 0);
        }


    	return false;
    }
};


int main(){
	int p1_[] = {1, 0};
	int p2_[] = {-1, 0};
	int p3_[] = {0, 1};
	int p4_[] = {0, -1};

	vector<int> p1;
	vector<int> p2;
	vector<int> p3;
	vector<int> p4;

	p1.assign(p1_, p1_+2);
	p2.assign(p2_, p2_+2);
	p3.assign(p3_, p3_+2);
	p4.assign(p4_, p4_+2);

	Solution s;
}















