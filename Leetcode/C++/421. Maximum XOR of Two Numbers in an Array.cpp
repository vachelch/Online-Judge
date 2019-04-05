class TrieNode{
public:
    map<int, TrieNode*> children;
    int val;
};

class Solution {
public:
	int mx = 0;

	void findMax(TrieNode* root, int num){
		long long tmp = 1;
		tmp <<= 31;

		TrieNode* cur = root;
		while(tmp){
			if(tmp & num){
				if (cur->children.find(0) != cur->children.end())
					cur = cur->children[0];
				else
					cur = cur->children[1];
			}
			else{
				if (cur->children.find(1) != cur->children.end())
					cur = cur->children[1];
				else
					cur = cur->children[0];
			}

			tmp >>= 1;
		}

		mx = max(cur->val ^ num, mx);
	}

	void Insert(TrieNode* root, int num){
		long long tmp = 1;
		tmp <<= 31;

		TrieNode* cur = root;

		while(tmp){
			if (tmp & num){
				if (cur->children.find(1) == cur->children.end()){
					TrieNode* node = new TrieNode;
    				cur->children[1] = node;
				}
				cur = cur->children[1];
			}
			else{
				if (cur->children.find(0) == cur->children.end()){
					TrieNode* node = new TrieNode;
    				cur->children[0] = node;
				}
				cur = cur->children[0];
			}
			tmp >>= 1;
		}

		cur->val = num;

	}
    int findMaximumXOR(vector<int>& nums) {
    	TrieNode* root = new TrieNode;

        for(int i=0; i< nums.size(); i++){
        	Insert(root, nums[i]);
        }
        
        for(int i=0; i< nums.size(); i++){
        	findMax(root, nums[i]);
        }

        return mx;
    }
};