class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int>res;
        vector<int>H(1001,0);
        for(auto it : nums[0])
        {
            H[it]++;
        }
        for(int i=1;i<nums.size();i++)
        {
            vector<int>HT(1001,0);
            for(auto it : nums[i])
            {
                if(H[it]>0)
                {
                    HT[it]++;
                }
            }
            H=HT;
        }
        for(int i=0;i<1001;i++)
        {
            while(H[i]--)
                res.push_back(i);
        }
        return res;
    }
};