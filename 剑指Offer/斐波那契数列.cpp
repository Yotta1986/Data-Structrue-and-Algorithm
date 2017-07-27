class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        
        int first = 0;
        int second = 1;
        int result;
        for(int i = 2; i <= n; i++)
        {
            result = first + second;
            
            first = second;
            second = result;
        }
        return result;
    }
};