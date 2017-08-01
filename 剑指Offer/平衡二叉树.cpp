class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot) return true;
        int leftDepth = TreeDepth(pRoot->left);
        int rightDepth = TreeDepth(pRoot->right);
        int diff = leftDepth - rightDepth;
        if(diff < -1 || diff > 1)
            return false;
        else 
            return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
        
    }
    
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot)
            return 0;
        
        int leftLength = TreeDepth(pRoot->left);
        int rightLength = TreeDepth(pRoot->right);
        return (leftLength > rightLength ? leftLength : rightLength) + 1;
        
    }
};