class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        
        if(numbers.size()< 5)
            return false;
        
        sort(numbers.begin(), numbers.end());
        
        int numberOfZero = 0;
        int numberOfGap = 0;
        
        // ͳ��������0�ĸ���
        for(auto number : numbers)
            if(number == 0) numberOfZero++;
        
        // ͳ�������еļ����Ŀ
        int small = numberOfZero;
        int big = small + 1;
        while(big < numbers.size())
        {
            // ������ȣ��ж��ӣ���������˳��
            if(numbers[small] == numbers[big])
                return false;
            
            numberOfGap += numbers[big] - numbers[small] - 1;
            small = big;
            big++;
        }
        return (numberOfGap > numberOfZero) ? false : true;
    }
};