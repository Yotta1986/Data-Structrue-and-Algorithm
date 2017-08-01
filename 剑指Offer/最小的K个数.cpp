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
                //��pop,Ȼ����������ɾ��
                pop_heap(result.begin(),result.end());
                result.pop_back();
                //���������м��룬��push
                result.push_back(input[i]);
                push_heap(result.begin(),result.end());
            }
        }
        //ʹ���С�������
        sort_heap(result.begin(),result.end());
        return result;
    }
};