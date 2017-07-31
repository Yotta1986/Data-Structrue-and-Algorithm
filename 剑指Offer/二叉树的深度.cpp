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
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot)
            return 0;
        
        int leftLength = TreeDepth(pRoot->left);
        int rightLength = TreeDepth(pRoot->right);
        return (leftLength > rightLength ? leftLength : rightLength) + 1;
        
    }
};