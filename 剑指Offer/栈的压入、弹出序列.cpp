class Solution {
public:
    // 模拟这个堆栈的过程，将将原数列依次压栈，栈顶元素与所给出栈队列相比，如果相同则出栈，
    // 如果不同则继续压栈，直到原数列中所有数字压栈完毕
    bool IsPopOrder(vector<int> pushV,vector<int> popV) 
    {
        if( pushV.size()==0 ||  popV.size() == 0)
            return false;
        
        stack<int> myStack;
        int popIndex = 0;
        for(int i = 0; i < pushV.size(); i++)
        {
            myStack.push(pushV[i]);
            while(!myStack.empty() && myStack.top() == popV[popIndex]) //!myStack.empty()是为了让myStack.top()不会指向无效内存
            {
                myStack.pop();
                popIndex++;
            }
        }
        return myStack.empty();
    }
};