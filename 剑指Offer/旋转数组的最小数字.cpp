class Solution {
public:
    // 使用两个指针不断地夹逼
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0) return 0;
        
        auto begin = rotateArray.begin();
        auto end = rotateArray.end() - 1;
        auto mid = (end - begin) / 2 + begin;
        
        while(end - begin > 1)
        {
            if(*mid >= *begin)
                begin = mid;
            else
                end = mid;
            mid = (end - begin) / 2 + begin;
        }
        
        return *end;
        
    }
};