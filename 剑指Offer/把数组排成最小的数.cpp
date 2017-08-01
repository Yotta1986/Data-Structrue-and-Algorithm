class Solution {
public:
    string PrintMinNumber(vector<int> numbers) 
    {
        sort(numbers.begin(), numbers.end(), whoShouldBeAhead);
        string result;
        for(auto number : numbers)
            result += to_string(number);
        return result;
    }
    
    static bool whoShouldBeAhead(int a, int b)
    {
        string A = "";
        string B = "";
        A += to_string(a);
        A += to_string(b);
        B += to_string(b);
        B += to_string(a);
        
        return A<B;
    }
};