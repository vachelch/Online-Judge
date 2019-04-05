/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#include <iostream>
#include <vector>
using namespace std;

class Interval{
public:
	int start;
	int end;
	Interval(int s, int e){
		start = s;
		end = e;
	}
};


// // stack
// bool cmp(vector<int>& a, vector<int>& b){
// 	return a[0] < b[0];
// }


// // Binary Search (STL), O(nlogn)
// class Solution {
// public:
// 	int binary_search(vector<vector<int> > itv, int i){
// 		int left = i + 1;
// 		int right = itv.size()-1;
// 		int mid;

// 		while(left < right){
// 			mid = (left + right) / 2;
// 			if(itv[mid][0] == itv[i][1]){
// 				left = right = mid;
// 				break;
// 			}
// 			else if(itv[mid][0] < itv[i][1])
// 				left = mid + 1;
// 			else
// 				right = mid;
// 		}

// 		if (left == right){
// 			if(itv[left][0] >= itv[i][1])
// 				return itv[left][2];
// 			else
// 				return -1;
// 		}
// 		else
// 			return -1;

// 	}
//     vector<int> findRightInterval(vector<Interval>& intervals) {
//         vector<vector<int> > itv;
//         for(int i=0; i< intervals.size(); i++){
//         	vector<int> v(3, 0);
//         	v[0] = intervals[i].start;
//         	v[1] = intervals[i].end;
//         	v[2] = i;
//         	itv.push_back(v);
//         }

//         sort(itv.begin(), itv.end(), cmp);

//         vector<int> res(itv.size(), 0);
//         for(int i=0; i<itv.size(); i++){
//         	int id_1 = itv[i][2];
//         	int id_2 = binary_search(itv, i);
//         	res[id_1] = id_2;
//         }	

//         return res;
//     }
// };

// Stack, O(n)
// stack
bool cmp(vector<int>& a, vector<int>& b){
	return a[0] >= b[0];
}

// elements
bool cmp2(vector<int>& a, vector<int>& b){
	return a[1] <= b[1];
} 
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<vector<int> > itv;
        vector<vector<int> > stack;

        for(int i=0; i< intervals.size(); i++){
        	vector<int> v(3, 0);
        	v[0] = intervals[i].start;
        	v[1] = intervals[i].end;
        	v[2] = i;
        	itv.push_back(v);
        }
        stack = itv;

        sort(stack.begin(), stack.end(), cmp); // start
        sort(itv.begin(), itv.end(), cmp2); // end

        vector<int> res(itv.size(), 0);
        for(int i=0; i<itv.size(); i++){
        	int id_1 = itv[i][2];
        	while(stack.size() != 0 && stack.back()[0] < itv[i][1])
        		stack.pop_back();

        	if (stack.size() == 0)
        		res[id_1] = -1;
        	else{
        		int id_2 = stack.back()[2];
        		res[id_1] = id_2;
        	}
        }	

        return res;
    }
};




int main(){
	Interval a(1,12);
	Interval b(2,9);
	Interval c(3,10);
	Interval d(13,14);
	Interval e(15,16);
	Interval f(16,17);

	vector<Interval> intervals;
	intervals.push_back(a);
	intervals.push_back(b);
	intervals.push_back(c);
	intervals.push_back(d);
	intervals.push_back(e);
	intervals.push_back(f);

	Solution s;
	vector<int> res = s.findRightInterval(intervals);
	for (auto r: res)
		cout << r << endl;

	return 0;
}