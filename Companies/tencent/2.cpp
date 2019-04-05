// AC
// Array, find the number which appears more than half times
class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        // check whether the num exist
        map<int, int> gift_cnt;
        for(auto gift: gifts){
        	if (gift_cnt.find(gift) != gift_cnt.end())
        		gift_cnt[gift] ++;
        	else
        		gift_cnt[gift] = 1;
        }
        int mx = 0;
        for(auto pair: gift_cnt){
        	mx = max(pair.second, mx);
        }
        if (2*mx <= gifts.size()) return 0;

        // do exist, find the number
        int cnt = 0;
        int res = gifts[0];
        for(int i=1; i< gifts.size(); i++){
        	if (res == gifts[0]){
        		cnt ++;
        	}
        	else{
        		if (cnt == 0){
        			res = gifts[i];
        			cnt = 1;
        		}
        		else
        			cnt --;
        	}
        }	

        return res;
    }
};