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
    void Mirror(TreeNode *pRoot) {
		if(!pRoot)
            return;
        
        // 有两棵子树
        if(pRoot->left && pRoot->right)
        {
            TreeNode* temp = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = temp;
            Mirror(pRoot->left);
            Mirror(pRoot->right);
            return;
        }
        
        // 只有左子树
        if(pRoot->left && !pRoot->right)
        {
            pRoot->right = pRoot->left;
            pRoot->left = nullptr;
            Mirror(pRoot->right);
        }
        // 只有右子树
        else if(!pRoot->left && pRoot->right)
        {
            pRoot->left = pRoot->right;
            pRoot->right = nullptr;
            Mirror(pRoot->left);
        }
        
    }
};