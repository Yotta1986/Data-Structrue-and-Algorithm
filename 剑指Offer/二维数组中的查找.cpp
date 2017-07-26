class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        
        // 判断输入合法性
        
        // 共有rows行，每行有columns个元素
        int rows = array.size();
        int columns = array[0].size();
        
        // 从右上角往左下角扫描
        int row = 0;
        int column = columns - 1;
        
        bool found = false;
        // 
        while(row < rows && column >=0 )
        {
            // 当前元素等于target，返回true
            if(array[row][column] == target)
            {
                found = true;
                break;
            }            
            // 当前元素小于target，下一次查找在当前元素下边查找，向下移动一行
            else if(array[row][column] < target)
            {
                row++;
            }
            // 当前元素大于target，下一次查找在当前元素左边查找，向左移动一列
            else
            {
                column--;
            }
        }
        
        return found;
    }
};