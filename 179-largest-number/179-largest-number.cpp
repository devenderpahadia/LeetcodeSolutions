class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end(), [](int a, int b){
           return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        string str="";
        for(auto it : nums)
        {
            string temp = to_string(it);
            str+=temp;
        }
        
        if(str[0]=='0')
            return "0";
        return str;
        
    }
};