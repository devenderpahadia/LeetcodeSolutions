class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size()==0)
            return 0;
        unordered_set<int>st;
        for(auto it : nums)
            st.insert(it);
        int mx = 1;
        int curr ;
        for(auto it : nums)
        {
            if(!st.count(it-1))
            {
                curr = it+1;
                int ctr = 1;
                while(st.count(curr))
                {
                    curr++;
                    ctr++;
                }
                mx = max(mx,ctr);
            }
        }
        return mx;
    }
};