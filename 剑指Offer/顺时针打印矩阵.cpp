class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) 
    {
        vector<int> result;
        int rows = matrix.size();
        int columns = matrix[0].size();
        if(rows <= 0 || columns <= 0)
            return result;
        
        // ��matrix[start][start]��Ϊ��ʼ�㻭ȦȦ
        int start = 0;
        
        while(columns > start *2 && rows > start *2)
        {
            PrintMatrixInCircle(matrix, start, result);
            
            start++;
        }
        return result;
    }
    
    void PrintMatrixInCircle(vector<vector<int> >& matrix, int start, vector<int>& result)
    {
        int rows = matrix.size();
        int columns = matrix[0].size();
        
        int endX = columns - 1 - start;
        int endY = rows - 1 - start;
        
        // �����Ҵ�ӡһ��
        for(int i = start; i <= endX; i++)
        {
            int number = matrix[start][i];
            result.push_back(number);
        }
        
        // ���ϵ��´�ӡһ��
        if(start < endY)
        {
            for(int i = start + 1; i <= endY; i++)
            {
                int number = matrix[i][endX];
                result.push_back(number);
            }
        }
        
        // ���ҵ����ӡһ��
        if(start < endX && start < endY)
        {
            for(int i = endX - 1; i >= start; i--)
            {
                int number = matrix[endY][i];
                result.push_back(number);
            }
        }
        
        // ���µ��ϴ�ӡһ��
        if(start < endX && start < endY - 1)
        {
            for(int i = endY - 1; i >= start + 1; i--)
            {
                int number = matrix[i][start];
                result.push_back(number);
            }
        }
        
    }
};