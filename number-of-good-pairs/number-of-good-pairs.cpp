class Solution {
public:
    int factorial(int n)
    {
        return (n*(n+1))/2;
    }
 
    int numIdenticalPairs(vector<int>& nums) {
        int sum = 0;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            if((it->second).size()>1)
            {
                int n = (it->second).size();
                cout<<n<<endl;
                sum+=(factorial(n-1));
            }
        }
        return sum;
    }
};