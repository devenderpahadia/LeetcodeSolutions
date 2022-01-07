class Solution {
public:
    void solve(int k,vector<int>nums,vector<int>temp,set<vector<int>>&ans)
    {
        if(temp.size()==nums.size())
        {
            ans.insert(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            auto it = find(temp.begin(),temp.end(),nums[i]);
            if(it!=temp.end())
            continue;
            temp.push_back(nums[i]);
            solve(i,nums,temp,ans);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>>res;
        set<vector<int>>ans;
        vector<int>temp;
        int i=0;
        solve(i,nums,temp,ans);
        for(auto x : ans)
        {
            res.push_back(x);
        }
        return res;
    }
};