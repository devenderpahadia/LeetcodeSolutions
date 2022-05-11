class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = -1;
        int num2 = -1;
        int ctr1 = 0;
        int ctr2 = 0;
        
        for(auto it : nums)
        {
            if(num1 == it)
                ctr1++;
            else if(num2 == it)
                ctr2++;
            else if(ctr1==0){
                num1 = it;
                ctr1 = 1;
            }
            else if(ctr2==0){
                num2 = it;
                ctr2=1;
            }
            else
            {
                ctr1--;
                ctr2--;
            }
        }
        
        ctr1 = 0;
        ctr2 = 0;
        
        for(auto it : nums)
        {
            if(num1 == it)
                ctr1++;
            if(num2 == it)
                ctr2++;
        }
        if(num1 ==num2)
            return {num1};
        vector<int>res;
        if(ctr1 > nums.size()/3)
            res.push_back(num1);
        if(ctr2 > nums.size()/3)
            res.push_back(num2);
        
        return res;
        
    }
};