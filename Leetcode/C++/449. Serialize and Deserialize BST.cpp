/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
	string code;
	vector<int> values;
	void dfs(TreeNode *root){
		if (root == NULL) return ;
		code += "1";
		values.push_back(root->val);

		if (root->left){
			dfs(root->left);
		}
		else
			code += "0";

		if (root->right){
			dfs(root->right);
		}
		else
			code += "0";

	}
	int idx;
	int val_id;
	TreeNode * decode(string data){
		if (data[idx] == '1'){
			TreeNode *root = new TreeNode(values[val_id++]);
			idx ++;
			root->left = decode(data);
			root->right = decode(data);
			return root;
		}
		else{
			idx ++;
			return NULL;
		}
	}
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        code = "";
        dfs(root);

        return code;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	idx = 0;
    	val_id = 0;
    	if (data.size() == 0) return NULL;
        return decode(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));







