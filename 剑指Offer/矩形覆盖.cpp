class Solution {
public:

// 和跳台阶一样，一次要么前进一格，要么前进两格

    int rectCover(int number) {
        if(number == 0)
            return 0;
        if(number == 1)
            return 1;
        if(number == 2)
            return 2;
        
        int BackStep1 = 2;
        int BackStep2 = 1;
        int result;
        
        // 当前台阶的跳法总数=当前台阶后退一阶的台阶的跳法总数+当前台阶后退二阶的台阶的跳法总数
        for(int i = 3; i <= number; i++)
        {
            result = BackStep1 + BackStep2;

            BackStep2 = BackStep1;// 后退一阶在下一次迭代变为后退两阶
 
            BackStep1 = result; // 当前台阶在下一次迭代变为后退一阶
        }
        return result;     
    }
};