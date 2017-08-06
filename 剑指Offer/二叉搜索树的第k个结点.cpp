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
    // 二叉搜索树的中序遍历序列是有序的
    queue<TreeNode*> Q;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot || k <= 0) return nullptr;
        KthNode(pRoot);
        for(int i = 1; i < k; i++)
            Q.pop();
        return Q.empty() ? nullptr : Q.front();
        
    }
    TreeNode* KthNode(TreeNode* pRoot)
    {
        if(!pRoot) return nullptr;
        KthNode(pRoot->left);
        Q.push(pRoot);
        KthNode(pRoot->right);
        return nullptr;
    }
    
};