class Solution {
public:
    vector<string> result;

    vector<string> Permutation(string str) {
        if(str.size() <= 0)
            return result;
        
        Permutation(&str[0], &str[0]);
        sort(result.begin(),result.end());
        return result;
    }
    
    void Permutation(char* pStr, char* pBegin)
    {
        if(*pBegin == '\0')
        {
            result.push_back(string(pStr));
        }
        else
        {
            for(char* pCh = pBegin; *pCh != '\0'; ++pCh)
            {
                if(pCh != pBegin && *pCh == *pBegin)
                    continue;
                
                char temp = *pCh;
                *pCh = *pBegin;
                *pBegin = temp;
                
                Permutation(pStr, pBegin + 1);
                
                temp = *pCh;
                *pCh = *pBegin;
                *pBegin = temp;
            }
        }
    }
};