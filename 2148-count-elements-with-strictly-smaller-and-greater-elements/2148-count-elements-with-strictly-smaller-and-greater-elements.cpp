class Solution {
public:
    int countElements(vector<int>& nums) {
        int ctr=0;
        for(int i=0;i<nums.size();i++)
        {
            bool flag = false;;
            for(int j=0;j<nums.size();j++)
            {
                if(i!=j)
                {
                    if(nums[j]<nums[i])
                    {
                        flag = true;
                        break;
                    }
                }
            }
            if(flag==false)
            {
                continue;
            }
            flag=false;
            for(int j=0;j<nums.size();j++)
            {
                if(i!=j)
                {
                    if(nums[j]>nums[i])
                    {
                        flag = true;
                        break;
                    }
                }
            }
            if(flag)
                ctr++;
        }
        return ctr;
    }
};