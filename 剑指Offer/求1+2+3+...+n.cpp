class Solution {
public:
    int Sum_Solution(int n) {
        int m = n;
        m && (m += Sum_Solution(n-1));
        return m;
    }
};