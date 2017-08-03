class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool isErrorHappen = false;
    
    bool duplicate(int numbers[], int length, int* duplication) {
        
        
        if(!numbers || length <= 0 || !duplication) 
        {
            isErrorHappen = true;
            *duplication = -1;
            return false;
        }
        
        vector<int> table(length, 0);
        for(int i = 0; i < length; i++)
            table[numbers[i]]++ ;
        
        for(int i = 0; i < length; i++)
            if(table[numbers[i]] >= 2)
            {
                *duplication = numbers[i];
                return true;
            }
        
        isErrorHappen = false;
        *duplication = -1;
        return false;
        
    }
};