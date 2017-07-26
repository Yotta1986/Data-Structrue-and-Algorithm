/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTreeCore(int* startPre, int* endPre, int* startIn, int* endIn)
    {
        // 前序遍历序列的第一个元素是根节点
        int rootValue = startPre[0];
        TreeNode* root = new TreeNode(rootValue);
        
        // 此次迭代已经到达叶子节点
        if(startPre == endPre && startIn == endIn && *startIn == *endIn)
        {
            return root;
        }
        
        // 在中序遍历序列中找到根节点
        int* rootIndex = startIn;
        while(rootIndex <= endIn && *rootIndex != rootValue)
            rootIndex++;
        
        // 判断合法性，保证(*rootIndex == rootValue)为真
        
        int LeftLength = rootIndex - startIn;
        int RightLenght = endIn - rootIndex;
            
        if(LeftLength > 0)
        {
            // 构建左子树
            root->left = reConstructBinaryTreeCore
                (startPre + 1, startPre + LeftLength, startIn, rootIndex - 1);
        }
        if(RightLenght > 0)
        {
            // 构建右子树
            root->right = reConstructBinaryTreeCore
                (startPre + LeftLength + 1, endPre, rootIndex + 1, endIn);
        }
        
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() <= 0 || vin.size() <= 0)
            return nullptr;
        return reConstructBinaryTreeCore(
            &pre[0],
            &pre[0] + (pre.size()-1),
            &vin[0],
            &vin[0] + (vin.size()-1)
            );
    }
};