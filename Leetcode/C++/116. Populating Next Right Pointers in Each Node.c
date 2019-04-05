/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	map<int, vector<TreeLinkNode*> >levels;
	void preorder(TreeLinkNode *root, int depth){
		if (root == NULL) return ;

		if (depth == levels.size())
			levels[depth] = vector<TreeLinkNode *>();
		
		levels[depth].push_back(root);

		preorder(root->left, depth + 1);
		preorder(root->right, depth + 1);
	}
    void connect(TreeLinkNode *root) {
        preorder(root, 0);

        int i=0;
        for(auto it: levels){
        	if (i++ == 0)
        		root = it.second[0];

        	else{
        		for(int j=0; j < it.second.size()-1; j++)
        			it.second[j]->next = it.second[j+1];
        	}
        }
    }
};