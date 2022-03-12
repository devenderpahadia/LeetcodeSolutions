class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        set<int>H;
        long long sum = (long long)k * (long long)(k+1) * 0.5;
        for(auto it : nums)
            H.insert(it);
        
        for(auto it : H)
        {
            if(it<=k) 
            {
                sum+=(++k - it);
            }
            else break;
        }
        
        return sum;
    }
};