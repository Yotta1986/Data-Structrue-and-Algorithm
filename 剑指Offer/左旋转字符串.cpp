class Solution {
public:
    string LeftRotateString(string str, int n) {
        int length = str.length();
        if(length <= 0) return "";
        n = n % length;
        str += str;
        return str.substr(n, length);
    }
};