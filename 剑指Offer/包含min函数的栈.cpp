class Solution {
public:
    stack<int> dataStack, minStack;
    
    void push(int value) 
    {
        dataStack.push(value);
        
        // 无论如何，dataStack 和 minStack 元素数量保存一致
        if(minStack.size() == 0 || value < minStack.top())// 当value >= minStack.top()时，minStack存入新的最小值
            minStack.push(value);
        else// 当value < minStack.top()时，minStack重复存入旧的最小值
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