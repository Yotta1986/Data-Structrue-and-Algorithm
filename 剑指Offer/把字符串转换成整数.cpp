class Solution {
public:
    int StrToInt(string str) {
        int result = 0;
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] > '9' || str[i] < '0') 
            {
                if(i == 0 && (str[i] == '+' || str[i] == '-'))
                    continue;
                else
                    return 0;
            }
            
            int number = str[i] - '0';
            result *= 10;
            result += number;
        }
        
        if(str[0] == '-')
            result = -result;
        return result;
    }
};