/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x){
		val = x;
		left = NULL;
		right = NULL;
	}
};


class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
    	if (N % 2 == 0) {
    		vector<TreeNode*> v;
    		return v;
    	}
        vector<vector<TreeNode*> > dp;
        TreeNode* node = new TreeNode(0);
        vector<TreeNode*> nodes;
        nodes.push_back(node);
        dp.push_back(nodes);

        
        for(int i=1; i<= (N-1)/2; i++){
        	vector<TreeNode*> nodes;

        	if ((i - 1) % 2 == 0){
	        	int cur = (i - 1) / 2;
	        	for(auto node_a: dp[cur]){
	        		for(auto node_b: dp[cur]){
	        			TreeNode* node = new TreeNode(0);
	        			node->left = node_a;
	        			node->right = node_b;
	        			nodes.push_back(node);
	        		}	
	        	}
	        }

	        for(int k=0; k< dp.size(); k++){
	        	for(int j=k+1; j< dp.size(); j++){
	        		if (k + j + 1 == i){
	        			for(auto node_a: dp[k]){
			        		for(auto node_b: dp[j]){
			        			TreeNode* node = new TreeNode(0);
			        			node->left = node_a;
			        			node->right = node_b;
			        			nodes.push_back(node);

			        			node = new TreeNode(0);
			        			node->left = node_b;
			        			node->right = node_a;
			        			nodes.push_back(node);
			        		}	
			        	}
	        		}
	        	}		
	        }

        	dp.push_back(nodes);
        }

        return dp[(N-1)/2];
    }
};

vector<string> tree_nodes;
void get_Tree(TreeNode* root){
	if (root == NULL){
		tree_nodes.push_back("null");
		return ;
	}
	tree_nodes.push_back(to_string(root->val));
	get_Tree(root->left);
	get_Tree(root->right);
}

int main(){
	Solution s;
	get_Tree(s.allPossibleFBT(7)[0]);

	for(auto val: tree_nodes)
		cout << val << " ";
	cout << endl;

	cout << s.allPossibleFBT(7).size() << endl;  


	return 0;
}






