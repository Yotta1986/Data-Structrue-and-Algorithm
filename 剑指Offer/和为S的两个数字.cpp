class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        if(array.size() < 2) return result;
        int begin = 0;
        int end = array.size() - 1;
        while(begin < end)
        {
            if(array[begin] + array[end] == sum)
            {
                result.push_back(array[begin]);
                result.push_back(array[end]);
                break;
            }
            else if(array[begin] + array[end] < sum)
                begin++;
            else
                end--;
        }
        return result;
    }
};