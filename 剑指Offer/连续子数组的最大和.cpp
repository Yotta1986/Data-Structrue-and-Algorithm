class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) 
    {
        int nowBegin, nowEnd, biggestBegin, biggestEnd, nowSum, biggestSum;
        nowBegin = nowEnd = biggestBegin = biggestEnd = nowSum = 0;
        biggestSum = 1 << sizeof(int)*8-1;
        for(; nowEnd < array.size(); nowEnd++)
        {
            if(nowSum < 0)
            {
                nowSum = array[nowEnd];
                nowBegin = nowEnd;
            }
            else
                nowSum += array[nowEnd];
            
            if(nowSum > biggestSum)
            {
                biggestSum = nowSum;
                biggestBegin = nowBegin;
                biggestEnd = nowEnd;
            }
        }
         
        return biggestSum;

    }
};