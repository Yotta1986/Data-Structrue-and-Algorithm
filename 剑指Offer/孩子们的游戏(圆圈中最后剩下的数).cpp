class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n < 1 || m < 1)
            return -1;
        
        // 先构造循环链表（仅仅约定当迭代器等于numbers.end()时，改成numbers.begin()，不存在实际连接）
        list<int> numbers;
        for(int i = 0; i < n; i++)
            numbers.push_back(i);
        
        list<int>::iterator current = numbers.begin();
        while(numbers.size() > 1)
        {
            // 找到第m个
            for(int i = 1; i < m; i++)
            {
                current++;
                if(current == numbers.end())
                    current = numbers.begin();
            }
            
            list<int>::iterator next = ++current;
            if(next == numbers.end())
                next = numbers.begin();
            
            --current;
            numbers.erase(current); 
            current = next; // 对于list，增加任何元素都不会使迭代器失效。删除元素时，除了指向当前被删除元素的迭代器外，其它迭代器都不会失效。因此next有效
        }
        return *current;
    }
};