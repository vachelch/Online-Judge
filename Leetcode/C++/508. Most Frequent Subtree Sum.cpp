/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int subtree_sum(TreeNode *root, map<int, int> &sum_cnt, int *mx, vector<int> &res){
	if (root == NULL)
		return 0;
	int sum = root->val + subtree_sum(root->left, sum_cnt, mx, res) + subtree_sum(root->right, sum_cnt, mx, res);
	if (sum_cnt.find(sum) == sum_cnt.end()){
		sum_cnt[sum] = 1;
	}
	else{
		sum_cnt[sum] ++;
	}

	if (sum_cnt[sum] > (*mx)){
		vector<int> tmp(1, sum);
		res = tmp;
		*mx = sum_cnt[sum];
	}
	else if (sum_cnt[sum] == (*mx)){
		res.push_back(sum);
	}
	return sum;
}

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        int mx = 0;
        map<int, int> sum_cnt;
        subtree_sum(root, sum_cnt, &mx, res);

        return res;
    }
};










/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
	vector<int> res;
    int mx = 0;
    map<int, int> sum_cnt;

    vector<int> findFrequentTreeSum(TreeNode* root) {
        subtree_sum(root);
        return res;
    }

    int subtree_sum(TreeNode *root){
		if (root == NULL) return 0;

		int sum = root->val + subtree_sum(root->left) + subtree_sum(root->right);
		if (sum_cnt.find(sum) == sum_cnt.end()){
			sum_cnt[sum] = 1;
		}
		else{
			sum_cnt[sum] ++;
		}

		if (sum_cnt[sum] > mx){
			vector<int> tmp(1, sum);
			res = tmp;
			mx = sum_cnt[sum];
		}
		else if (sum_cnt[sum] == mx){
			res.push_back(sum);
		}
		return sum;
	}
};






















