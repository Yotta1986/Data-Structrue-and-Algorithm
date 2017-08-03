class Solution {
public:
    string ReverseSentence(string str) {
        if(str.size() <= 1) return str;
        
        ReverseWord(str, 0, str.length()-1); // 先整体翻转
        
        int begin, end;
        begin = end = 0;
        int i = 0;
        while(i < str.length())
        {
            while(i < str.length() && str[i] == ' ') // 空格跳过
                i++;
            end = begin = i; // 记录单词的第一个字符的位置
            while(i < str.length() && str[i] != ' ') // 不是空格 找单词最后一个字符的位置
            {
                i++; end++;
            }
            ReverseWord(str, begin, end-1); // 翻转单词
        }
        
        return str;
    }
    

//翻转str从s到e的部分
    void ReverseWord(string &str, int begin, int end)
    {
        while(begin < end)
            swap(str[begin++], str[end--]);
    }

    
    
};