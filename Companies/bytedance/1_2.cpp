#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

// int main(){
// 	int n, m;
// 	string s;
// 	while(cin >> n >> m){
// 		cin >> s;

// 		if (2*m >= n){
// 			cout << n << endl;
// 			continue;	
// 		} 
// 		vector<int> a_count(n, 0);
// 		// memset(a_count, 0, sizeof(int)* n);
// 		int sum = 0;
// 		for(int i=0; i< n; i++){
// 			sum += ('a' == s[i]);
// 			a_count[i] = sum;
// 		}

// 		int mx = min(2*m, n);

// 		for(int l=0; l< n; l++){
// 			for(int r=l+2*m; r< n; r++){
// 				int a_num = a_count[r] - a_count[l] + (s[l] == 'a');
// 				if (a_num <= m || r-l+1-a_num <= m){
// 					mx = max(r - l+1, mx);
// 				}
// 			}
// 		}
// 		cout << mx << endl;
// 	}

// 	return 0;
// }

// int main(){
// 	int n, m;
// 	string s;
// 	while(cin >> n >> m){
// 		cin >> s;
// 		vector<pair<int, int> > sum_ab;
// 		int a_cnt = (s[0] == 'a'), b_cnt = (s[0] == 'b');
// 		char last = s[0];
// 		for(int i=1; i< s.size(); i++){
// 			a_cnt += (s[i] == 'a');
// 			b_cnt += (s[i] == 'b');

// 			if (s[i] != last){
// 				sum_ab.push_back(make_pair(a_cnt, b_cnt));
// 				last = s[i];
// 			}
// 		}

// 		for(int l=0; l< sum_ab.size(); l++){
// 			for(int r=l; r< sum_ab.size(); r++){
// 				int a_num = sum_ab[r].first - sum_ab[r].first + ;
// 				int b_num = ;
// 			}
// 		}
// 	}

// 	return 0;
// }





// int main(){
// 	int n, m;
// 	string s;
// 	while(cin >> n >> m){
// 		cin >> s;

// 		if (2*m >= n){
// 			cout << n << endl;
// 			continue;	
// 		} 
// 		vector<int> a_count(n, 0);
// 		// memset(a_count, 0, sizeof(int)* n);
// 		int sum = 0;
// 		for(int i=0; i< n; i++){
// 			sum += ('a' == s[i]);
// 			a_count[i] = sum;
// 		}

// 		int mx = min(2*m, n);

// 		for(int l=0; l< n; l++){
// 			for(int r=l+2*m; r< n; r++){
// 				int a_num = a_count[r] - a_count[l] + (s[l] == 'a');
// 				if (a_num <= m || r-l+1-a_num <= m){
// 					mx = max(r - l+1, mx);
// 				}
// 			}
// 		}
// 		cout << mx << endl;
// 	}

// 	return 0;
// }


int main(){
	int n, m;
	string s;
	while(cin >> n >> m){
		cin >> s;
		char last = s[0];
		vector<int> ab_count;
		int cur_cnt = 1;
		for(int i=1; i< s.size(); i++){
			if (last == s[i]){
				cur_cnt ++;
			}
			else{
				if (last == 'b')
					cur_cnt = -1 * cur_cnt;
				ab_count.push_back(cur_cnt);
				last = s[i];
				cur_cnt = 1;
			}
		}

		int size = ab_count.size();
		vector<int> pos_vec(size, 0);
		vector<int> neg_vec(size, 0);

		int pos = 0;
		int neg = 0;
		for(int i=0; i < size; i++){
			if (ab_count[i] > 0) pos += ab_count[i];
			else neg += ab_count[i] * -1;

			pos_vec[i] = pos;
			neg_vec[i] = neg;
		}

		int mx = INT_MIN;
		for(int l=0; l< size; l++){
			for(int r=l; r< size; r++){
				int cnt = 0;
				if (ab_count[l] > 0) cnt = ab_count[l];
				int cnt_pos = pos_vec[r] - pos_vec[l] + cnt; 

				cnt = 0;
				if (ab_count[l] < 0) cnt = ab_count[l] * -1;
				int cnt_neg = neg_vec[r] - neg_vec[l] + cnt;

				if (cnt_pos <= m){
					mx = max(mx, (cnt_pos + cnt_neg + m - cnt_pos));
				}
				if (cnt_neg <= m){
					mx = max(mx, (cnt_pos + cnt_neg + m - cnt_neg));
				}
			}
		}

		cout << min(mx, n) << endl;	
	}

	return 0;
}



















