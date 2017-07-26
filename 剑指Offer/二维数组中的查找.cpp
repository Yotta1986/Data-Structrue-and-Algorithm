class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        
        // �ж�����Ϸ���
        
        // ����rows�У�ÿ����columns��Ԫ��
        int rows = array.size();
        int columns = array[0].size();
        
        // �����Ͻ������½�ɨ��
        int row = 0;
        int column = columns - 1;
        
        bool found = false;
        // 
        while(row < rows && column >=0 )
        {
            // ��ǰԪ�ص���target������true
            if(array[row][column] == target)
            {
                found = true;
                break;
            }            
            // ��ǰԪ��С��target����һ�β����ڵ�ǰԪ���±߲��ң������ƶ�һ��
            else if(array[row][column] < target)
            {
                row++;
            }
            // ��ǰԪ�ش���target����һ�β����ڵ�ǰԪ����߲��ң������ƶ�һ��
            else
            {
                column--;
            }
        }
        
        return found;
    }
};