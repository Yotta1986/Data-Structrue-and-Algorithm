class Solution {
public:
    /*
    step1:��λ���ǲ鿴��������Щ������λ��Ϊ1����Щ���ǽ�λλ�����������һλ����ʾ��λ��Ľ�� 
    step2:����ǲ鿴��������Щ������λֻ��һ��Ϊ1����Щ�Ƿǽ�λλ������ֱ�Ӽӡ����������ʾ�ǽ�λλ���мӲ�����Ľ�� 
    step3:n1&n2�ǲ鿴��û�н�λλ�ˣ�����У���Ҫ�ظ�step1��step2�����û�У�����n1��n2�϶�����Ϊ1�Ĳ��֣��û�֮��Ϊһ��������Ϊ�����
    */
    int Add(int num1, int num2)
    {
        int sum = 0, carry = 0;
        do
        {
            carry = (num1 & num2) << 1;
            sum = num1 ^ num2;
            
            num1 = sum; num2 = carry;
        }
        while(carry != 0);
        
        return sum;
    }
};