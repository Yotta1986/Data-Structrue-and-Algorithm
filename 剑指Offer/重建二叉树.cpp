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
        // ǰ��������еĵ�һ��Ԫ���Ǹ��ڵ�
        int rootValue = startPre[0];
        TreeNode* root = new TreeNode(rootValue);
        
        // �˴ε����Ѿ�����Ҷ�ӽڵ�
        if(startPre == endPre && startIn == endIn && *startIn == *endIn)
        {
            return root;
        }
        
        // ����������������ҵ����ڵ�
        int* rootIndex = startIn;
        while(rootIndex <= endIn && *rootIndex != rootValue)
            rootIndex++;
        
        // �жϺϷ��ԣ���֤(*rootIndex == rootValue)Ϊ��
        
        int LeftLength = rootIndex - startIn;
        int RightLenght = endIn - rootIndex;
            
        if(LeftLength > 0)
        {
            // ����������
            root->left = reConstructBinaryTreeCore
                (startPre + 1, startPre + LeftLength, startIn, rootIndex - 1);
        }
        if(RightLenght > 0)
        {
            // ����������
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