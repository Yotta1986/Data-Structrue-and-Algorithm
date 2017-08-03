class Solution {
public:
    /*
    使用状态机实现的，代码简单但是比较啰嗦。
    一共有六个状态：SYMBOL，INTEGER，DECIMAL，EXPONENT_SYMBOL，EXPONENT_INTEGER，END等。
    */
    bool isNumeric(char* string)
    {
        if(!string) return false;
        
        bool result = false;
        
        int i = 0;

SYMBOL:
        if(string[i] == '+' || string[i] == '-')
        {
            result = false;
            if(string[++i] == '\0') goto END;
            else goto INTEGER;
        }
        else if(isNum(string[i]))
        {
            result = true;
            if(string[++i] == '\0') goto END;
            else goto INTEGER;
        }
        else
        {
            result = false;
            goto END;
        }
        
        
INTEGER:
        if(isNum(string[i]))
        {
            result = true;
            if(string[++i] == '\0') goto END;
            else goto INTEGER;
        }
        else if(string[i] == '.')
        {
            result = false;
            if(string[++i] == '\0') goto END;
            goto DECIMAL;
        }
        else if(string[i] == 'e' || string[i] == 'E')
        {
            result = false;
            if(string[++i] == '\0') goto END;
            goto EXPONENT_SYMBOL;
        }
        else
        {
            result = false;
            goto END;
        }
            
DECIMAL:
        if(isNum(string[i]))
        {
            result = true;
            if(string[++i] == '\0') goto END;
            else goto DECIMAL;
        }
        else if(string[i] == 'e' || string[i] == 'E')
        {
            result = false;
            if(string[++i] == '\0') goto END;
            goto EXPONENT_SYMBOL;
        }
        else
        {
            result = false;
            goto END;
        }
        
EXPONENT_SYMBOL:
        if(string[i] == '+' || string[i] == '-')
        {
            result = false;
            if(string[++i] == '\0') goto END;
            else goto EXPONENT_INTEGER;
        }
        else if(isNum(string[i]))
        {
            result = true;
            if(string[++i] == '\0') goto END;
            else goto EXPONENT_INTEGER;
        }
        else
        {
            result = false;
            goto END;
        }
        
EXPONENT_INTEGER:
        if(isNum(string[i]))
        {
            result = true;
            if(string[++i] == '\0') goto END;
            else goto EXPONENT_INTEGER;
        }
        else
        {
            result = false;
            goto END;
        }
        
END:
        return result;
    }
    
    bool isNum(char ch)
    {
        if(ch<'0'||ch>'9') return false;
        else return true;
    }

};