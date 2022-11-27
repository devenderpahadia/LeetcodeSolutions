#define LL long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int n = nums.size();
        vector<map<LL,int> > vec(n);
        LL res=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                LL temp = (LL)nums[i] - (LL)nums[j];
                int sum=0;
                if(vec[j].find(temp)!=vec[j].end())
                {
                    sum = vec[j][temp];
                }
                vec[i][temp]+=sum+1;
                res += sum;
            }
        }
        return (int)res;
    }
};