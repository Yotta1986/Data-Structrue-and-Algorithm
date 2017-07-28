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
        
        // ��BST���������Ľڵ��С�ڸ��ڵ�
        int i = 0;
        for(; i < length - 1; i++)
        {
            if(sequence[i] > root)
                break;
        }
        int leftLength = i;
        
        // ��BST���������Ľڵ��С�ڸ��ڵ�
        int j = leftLength;
        for(; j < length - 1; j++)
        {
            if(sequence[j] < root)
                return false;
        }
        
        // �ж��������ǲ��Ƕ�����
        // Ĭ��Ϊture��Ϊ��Ӧ���ڵ�Ϊ�յ����
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