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
using namespace std;

class TreeNode{
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x){
		val = x;
		left = NULL;
		right = NULL;
	}
};

// beat 35.87%
class Solution {
public:
	TreeNode* preorder(TreeNode *root){
		if (!root) return NULL;
		TreeNode *head = root;

		TreeNode *left = preorder(root->left);
		TreeNode *right = preorder(root->right);

		root->right = left;
		root->left = NULL;

		while(root->right){
			root = root->right;
			root->left = NULL;
		}

		root->right = right;


		return head;
	}
    void flatten(TreeNode* root) {
        root = preorder(root);
    }
};


// beat 100%
class Solution {
public:
	TreeNode *prev = NULL;
    void flatten(TreeNode* root) {
        if (root == NULL) return ;
        
        flatten(root->right);
        flatten(root->left);

        root->left = NULL;
        root->right = prev;
        prev = root;
    }
};

int main(){
	TreeNode * n1 = new TreeNode(1);
	TreeNode * n2 = new TreeNode(2);
	TreeNode * n3 = new TreeNode(5);
	TreeNode * n4 = new TreeNode(3);
	TreeNode * n5 = new TreeNode(4);
	TreeNode * n6 = new TreeNode(6);

	n1->left = n2;
	n1->right = n3;
	
	n2->left = n4;
	n2->right = n5;

	n3->right = n6;



	Solution s;
	s.flatten(n1);
	while(n1){
		cout << n1->val << " ";
		n1 = n1->right;
	}
	cout << endl;

	return 0;
}