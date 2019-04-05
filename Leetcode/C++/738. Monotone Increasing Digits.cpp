class Solution {
public:
	string monotone(string N){
		int isMonot = 1;
		for(int i=1; i< N.size(); i++){
			if (!isMonot)
				N[i] = '9';
			else if (N[i] < N[i-1]){
				int cur = i;
				N[cur] = N[cur] - 1;
				while(N[cur] == ('0' - 1)){
					N[cur] = '9';
					cur --;
					N[cur] = N[cur] - 1;
				}
				isMonot = 0;
			}
		}

		if (N[0] == '0' && N.size() != 1)
			N = N.substr(1, N.size()-1);

		if (isMonot)
			return N;
		else
			return monotone(N);
	}
    int monotoneIncreasingDigits(int N) {
        return stoi(monotone(to_string(N)));
    }
};