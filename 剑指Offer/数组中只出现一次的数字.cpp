class Solution {
public:
    /*
    1、异或思想，一个数与自己异或为0，一个数与0异或为自己 
    2、由于其它数字两两相同，所以所有数异或则得到这两个不同数的异或结果。取这个结果的第一个1作为标志位 
    3、这个标志的1，必须是：这两个数在该位一个为0，一个为1 
    4、这样可以将数组分为两组，一组在该标志位为1，一组在该标志位为0，这两个不同数字分别在这两组内 
    5、将两组内的数分别异或，得到两个结果则为这两个不同的数
    */
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) 
    {
        int num = 0;
        for(int i = 0; i < data.size(); i++)
             num ^= data[i];// 所有数的异或，最终结果为不同的两个数字的异或
        
        int count = 0;// 标志位，记录num中的第一个1出现的位置
        for(; count < data.size(); count++)
        {
            if( (num&(1<<count)) != 0 )
                break;
        }
        
        *num1 = *num2 = 0;
        for(int i = 0; i < data.size(); i++)
        {
            if( (data[i]&(1<<count)) == 0 ) 
                *num1 ^= data[i]; // 对所有该标志位为0的进行异或
            else 
                *num2 ^= data[i]; // 对所有该标志位为1的进行异或
        }
    }
};