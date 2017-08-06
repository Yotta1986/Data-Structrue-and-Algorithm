class Solution {
public:
    int GetUglyNumber_Solution(int index) 
    {
        if(index < 1) return 0;
        
        vector<int> result;
        result.push_back(1);
        
        int t2 = 0, t3 = 0, t5 = 0;
        int nextIndex = 1;
        int minNum;
        while(nextIndex < index)
        {
            minNum = min(result[t2]*2, min(result[t3]*3, result[t5]*5));
            result.push_back(minNum);
            
            while(result[t2]*2 <= minNum)
                t2 += 1;
            while(result[t3]*3 <= minNum)
                t3 += 1;
            while(result[t5]*5 <= minNum)
                t5 += 1;
            
            nextIndex += 1;
        }
        
        return result[nextIndex - 1];
    }
};