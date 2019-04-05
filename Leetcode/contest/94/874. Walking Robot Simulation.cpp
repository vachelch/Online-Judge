class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    	int res = 0;
    	int x= 0, y = 0;
    	int x_v[] = {0, 1, 0, -1};
    	int y_v[] = {1, 0, -1, 0};
    	int di = 0;
		set<pair<int, int>>obs;

        for(int i=0; i< obstacles.size(); i++)
        	obs.insert(make_pair(obstacles[i][0], obstacles[i][1]));

        for(int i=0; i< commands.size(); i++){
        	if(commands[i] == -2){
        		di = (di + 4 - 1) % 4;
        	}
        	else if(commands[i] == -1){
        		di = (di + 1) % 4;
        	}
        	else{
        		for(int j=0; j< commands[i]; j++){
        			if (obs.find(make_pair(x+x_v[di], y+y_v[di])) == obs.end()){
        				x += x_v[di];
        				y += y_v[di];
        				res = max(x*x + y*y, res);

        			}
        			else
        				break;
        		}
        	}
        }

        return res;
    }
};

























