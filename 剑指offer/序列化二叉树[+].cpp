/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    char buffer[100000];
    string dfs(TreeNode *root){
        if (root == NULL){
            return ",";
        }
        
        return to_string(root->val)+ "," + dfs(root->left) + dfs(root->right);
    }
    TreeNode* de_dfs(char* str, int &idx){
        if (str[idx] == ',') {
            idx ++;
            return NULL;
        }
        
        string cur_num;
        while(str[idx] != ','){
            cur_num.push_back(str[idx]);
            idx ++;
        }
        idx ++;
        
        TreeNode* root = new TreeNode(stoi(cur_num));
        root->left = de_dfs(str, idx);
        root->right = de_dfs(str, idx);
        
        return root;
    }
    char* Serialize(TreeNode *root) {
        string str = dfs(root);
        strncpy(buffer, str.c_str(), sizeof(buffer));
        return buffer;
    }
    TreeNode* Deserialize(char *str) {
        int idx = 0;
        return de_dfs(str, idx);
    }
};