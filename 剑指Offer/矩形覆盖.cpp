class Solution {
public:

// ����̨��һ����һ��Ҫôǰ��һ��Ҫôǰ������

    int rectCover(int number) {
        if(number == 0)
            return 0;
        if(number == 1)
            return 1;
        if(number == 2)
            return 2;
        
        int BackStep1 = 2;
        int BackStep2 = 1;
        int result;
        
        // ��ǰ̨�׵���������=��ǰ̨�׺���һ�׵�̨�׵���������+��ǰ̨�׺��˶��׵�̨�׵���������
        for(int i = 3; i <= number; i++)
        {
            result = BackStep1 + BackStep2;

            BackStep2 = BackStep1;// ����һ������һ�ε�����Ϊ��������
 
            BackStep1 = result; // ��ǰ̨������һ�ε�����Ϊ����һ��
        }
        return result;     
    }
};