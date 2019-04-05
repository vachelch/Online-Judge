#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		vector<int> trans(n+1);
		vector<int> cnt(n+1, 0);
		for(int i=1; i<= n; i++)
			cin >> trans[i];

		int cur = 1;
		int step = 0;
		while(cur != n+1){
			cnt[cur] = (cnt[cur] == 0);
			
			if (cnt[cur] == 1){
				cur = trans[cur];
			}
			else{
				cur ++;
			}
			
			step++;
			if (step > 1000000007) step = step % 1000000007;
		}

		cout << step % 1000000007 << endl;

	}

	return 0;
}

// // python dp
// // dp[i] = dp[i-1] +f(i-1,i) = dp[i-1]+1+f(home[i-1],i-1)+1 = dp[i-1]+1 +dp[i-1]-dp[home[i-1]]+1=2dp[i-1] - dp[home[i-1]]+2
// n = int(input())
// home = [int(e)-1 for e in input().split()]
// dp = [0 for _ in range(n+1)]
// dp[1] = 2
// for i in range(2,n+1):
//     dp[i] = 2*dp[i-1] - dp[home[i-1]]+2
// print(dp[n]%1000000007)


























