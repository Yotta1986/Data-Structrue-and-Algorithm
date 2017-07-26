class Solution 
{
public:
	void replaceSpace(char *str,int length) 
    {
        if(str && length>0)
        {
            int spaceNum = 0;
            for(int i=0; i<length; i++)// count space
            {
				if(str[i]==' ')
                    spaceNum++;
            }
            
            for(int i=length-1; 0<=i; i--)// replace from end to begining
            {           
                if(str[i]==' ')// find space
                {   
					str[i + spaceNum*2] = '0';					
                    str[i + spaceNum*2 - 1] = '2';					
                    str[i + spaceNum*2 - 2] = '%';
                    spaceNum--;
                }
                else
                {
                    str[i + spaceNum*2] = str[i];
                }
            }              
        }// end of first if
	}
};