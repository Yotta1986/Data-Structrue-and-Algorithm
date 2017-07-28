class Solution {
public:
    stack<int> dataStack, minStack;
    
    void push(int value) 
    {
        dataStack.push(value);
        
        // ������Σ�dataStack �� minStack Ԫ����������һ��
        if(minStack.size() == 0 || value < minStack.top())// ��value >= minStack.top()ʱ��minStack�����µ���Сֵ
            minStack.push(value);
        else// ��value < minStack.top()ʱ��minStack�ظ�����ɵ���Сֵ
            minStack.push(minStack.top());
    }
    
    void pop() 
    {
        minStack.pop();
        dataStack.pop();
    }
    
    int top() 
    {
        return dataStack.top();
    }
    
    int min() 
    {
        return minStack.top();
    }
};