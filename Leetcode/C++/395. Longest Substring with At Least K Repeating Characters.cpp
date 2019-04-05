#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

// // brute force, change structure of chrs from vector to map, will cause TLE
// class Solution {
// public:
//     int longestSubstring(string s, int k) {
//     	int size = s.size();

//     	vector<int> chrs;
//         int res = 0;
        
//         for(int d = k; d<= size; d++){
//         	for(int i = 0; i+d-1 < size; i++){
//         		if (i == 0){
//         			// prepare dict
//         			chrs.clear();
//         			chrs.assign(26, 0);

//         			for(int j=0; j< d; j++)
//         				chrs[s[j] - 'a'] ++;
//         		}
//         		else{
//         			chrs[s[i+d-1]- 'a'] ++;
//         			chrs[s[i-1]- 'a'] --;
//         		}

//         		// find minimum
//         		int has_sub = 1;
//         		for(auto n: chrs){
//         			if (0< n && n < k){
//         				has_sub = 0;
//         				break;
//         			}
//         		}

//         		if(has_sub){
//         			res = d;
//         			break;
//         		}
//         	}
//         }

//         return res;
//     }
// };

// divide and conquer, beat 100%
class Solution {
public:
	int helper(string s, int k, int l, int r){
		if (r - l + 1 < k) return 0;

		vector<int> chrs(26, 0);
		for(int i=l; i<= r; i++){ chrs[s[i]-'a']++;}


		int left = l, right;
		int res = 0;

		while(left <= r){
			while(left <= r && chrs[s[left] - 'a'] < k) left++;
			right = left;
			while(right <=r && chrs[s[right] - 'a'] >= k) right ++;
			right --;

			if (l == left && r == right)
				return right - left + 1;

			res = max(res, helper(s, k, left, right));
			left = right + 1;
		}

		return res;
	}
    int longestSubstring(string s, int k) {
        return helper(s, k, 0, s.size()-1);
    }
};


int main(){
	string s = "ababbc";
	int k = 3;
	
	Solution sl;
	cout << sl.longestSubstring(s, k) << endl;

	return 0;
}




























