class Solution {
public:
    string ReverseSentence(string str) {
        if(str.size() <= 1) return str;
        
        ReverseWord(str, 0, str.length()-1); // �����巭ת
        
        int begin, end;
        begin = end = 0;
        int i = 0;
        while(i < str.length())
        {
            while(i < str.length() && str[i] == ' ') // �ո�����
                i++;
            end = begin = i; // ��¼���ʵĵ�һ���ַ���λ��
            while(i < str.length() && str[i] != ' ') // ���ǿո� �ҵ������һ���ַ���λ��
            {
                i++; end++;
            }
            ReverseWord(str, begin, end-1); // ��ת����
        }
        
        return str;
    }
    

//��תstr��s��e�Ĳ���
    void ReverseWord(string &str, int begin, int end)
    {
        while(begin < end)
            swap(str[begin++], str[end--]);
    }

    
    
};