class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) 
    {
        return VerifySquenceOfBSTCore(&sequence[0], sequence.size());
    }
    bool VerifySquenceOfBSTCore(int sequence[], int length) 
    {
        if(length <= 0 || sequence == nullptr)
            return false;
        
        int root = sequence[length - 1];
        
        // 在BST中左子树的节点均小于根节点
        int i = 0;
        for(; i < length - 1; i++)
        {
            if(sequence[i] > root)
                break;
        }
        int leftLength = i;
        
        // 在BST中右子树的节点均小于根节点
        int j = leftLength;
        for(; j < length - 1; j++)
        {
            if(sequence[j] < root)
                return false;
        }
        
        // 判断左子树是不是二叉树
        // 默认为ture是为了应付节点为空的情况
        bool left = true;
        if(leftLength > 0)
            left = VerifySquenceOfBSTCore(sequence, leftLength);
        
        
        //
        bool right = true;
        if(i < length - 1)
        {
            right = VerifySquenceOfBSTCore(sequence + i, length - i - 1);
        }
        
        return left && right;
    }
};