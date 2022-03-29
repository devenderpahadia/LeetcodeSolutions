class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int H[100001]={0};
        for(int i=0;i<nums.size();i++)
        {
            H[nums[i]]++;
            if(H[nums[i]]>1)
            {
                return nums[i];
            }
        }
        return -1;
    }
};