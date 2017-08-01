class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.length() <= 0) return -1;
        
        unsigned int hashTable[256] = {0};
        
        int i;
        for(i = 0; i < str.length(); i++)
        {
            hashTable[(unsigned int)str[i]]++;
        }
        
        for(i = 0; i < str.length(); i++)
        {
            
            if(hashTable[(unsigned int)str[i]] == 1)
                return i;
        }
        
        return -1;
    }
};