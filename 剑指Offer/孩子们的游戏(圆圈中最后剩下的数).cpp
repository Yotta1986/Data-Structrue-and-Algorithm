class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n < 1 || m < 1)
            return -1;
        
        // �ȹ���ѭ����������Լ��������������numbers.end()ʱ���ĳ�numbers.begin()��������ʵ�����ӣ�
        list<int> numbers;
        for(int i = 0; i < n; i++)
            numbers.push_back(i);
        
        list<int>::iterator current = numbers.begin();
        while(numbers.size() > 1)
        {
            // �ҵ���m��
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
            current = next; // ����list�������κ�Ԫ�ض�����ʹ������ʧЧ��ɾ��Ԫ��ʱ������ָ��ǰ��ɾ��Ԫ�صĵ������⣬����������������ʧЧ�����next��Ч
        }
        return *current;
    }
};