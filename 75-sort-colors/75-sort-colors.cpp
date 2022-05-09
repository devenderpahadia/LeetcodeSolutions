class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        vector<int>H(3);
        for(int i=0;i<nums.size();i++)
            H[nums[i]]++;
        int j=0;
        for(int i=0;i<3;i++)
            while(H[i]--)   nums[j++]=i;
    }
};