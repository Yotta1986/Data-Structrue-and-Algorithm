class Solution {
public:
    void reOrderArray(vector<int> &array) {
        // array1����������array2����ż��
        vector<int> array1, array2;
        for(auto integer : array)
        {
            if(integer % 2 == 1)
                array1.push_back(integer);
            else
                array2.push_back(integer);
        }
        array.clear();
        for(auto integer : array1)
            array.push_back(integer);
        for(auto integer : array2)
            array.push_back(integer);
    }
};