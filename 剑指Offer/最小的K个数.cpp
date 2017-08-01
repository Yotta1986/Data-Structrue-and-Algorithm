class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        
        if(input.size() <= 0 || k > input.size() || k <= 0) return vector<int>();
        
        vector<int> result;
        for (int i = 0; i < k; i++) 
            result.push_back(input[i]);
        
        make_heap(result.begin(), result.end());
        
        for(int i = k; i < input.size(); i++)
        {
            if(input[i] < result[0])
            {
                //先pop,然后在容器中删除
                pop_heap(result.begin(),result.end());
                result.pop_back();
                //先在容器中加入，再push
                result.push_back(input[i]);
                push_heap(result.begin(),result.end());
            }
        }
        //使其从小到大输出
        sort_heap(result.begin(),result.end());
        return result;
    }
};