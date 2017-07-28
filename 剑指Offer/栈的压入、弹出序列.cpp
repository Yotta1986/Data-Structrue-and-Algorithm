class Solution {
public:
    // ģ�������ջ�Ĺ��̣�����ԭ��������ѹջ��ջ��Ԫ����������ջ������ȣ������ͬ���ջ��
    // �����ͬ�����ѹջ��ֱ��ԭ��������������ѹջ���
    bool IsPopOrder(vector<int> pushV,vector<int> popV) 
    {
        if( pushV.size()==0 ||  popV.size() == 0)
            return false;
        
        stack<int> myStack;
        int popIndex = 0;
        for(int i = 0; i < pushV.size(); i++)
        {
            myStack.push(pushV[i]);
            while(!myStack.empty() && myStack.top() == popV[popIndex]) //!myStack.empty()��Ϊ����myStack.top()����ָ����Ч�ڴ�
            {
                myStack.pop();
                popIndex++;
            }
        }
        return myStack.empty();
    }
};