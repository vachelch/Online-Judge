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
    TreeNode* de_inorder(string data, int *idx){
        if (data[*idx] == ',') {
            (*idx) += 1;
            return NULL;   
        }
        
        int size = stoi(data.substr(*idx, 2));
        (*idx) += 2;
        TreeNode* root = new TreeNode(stoi(data.substr(*idx, size)));
        (*idx) += size;
        
        TreeNode* left = de_inorder(data, idx);
        TreeNode* right = de_inorder(data, idx);
        root->left = left;
        root->right = right;
        
        return root;
    }
    string encode(int val){
        string str = to_string(val);
        if (val > 0)
            str = "+" + str;

        int size = str.size();
        string size_str = to_string(size);

        if (size < 10)
            size_str = "0" + size_str;

        return size_str + str;
    }

    string preorder(TreeNode* root){
        if (!root) return ",";
        
        string str = encode(root->val);
        string left = preorder(root->left);
        string right = preorder(root->right);
        
        return str + left + right;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = preorder(root);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        deque<TreeNode*> queue;
        int idx = 0;
        return de_inorder(data, &idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));