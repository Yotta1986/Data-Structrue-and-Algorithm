/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        
        vector<int> result;
        if(!root)
            return result;
        queue<TreeNode*> myQueue;
        
        myQueue.push(root);
        while(!myQueue.empty())
        {
            TreeNode* node = myQueue.front();
            result.push_back(node->val);
            if(node->left)
                myQueue.push(node->left);
            if(node->right)
                myQueue.push(node->right);
                
            myQueue.pop();
        }
        return result;
    }
};