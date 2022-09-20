class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        int x=nums1.size();
        int y=nums2.size();
        
        int t[x+1][y+1];
        
        for(int i=0;i<x+1;i++)
        {
            t[i][0]=0;
        }
        for(int i=0;i<y+1;i++)
        {
            t[0][i]=0;
        }
        int mx=0;
        for(int i=1;i<x+1;i++)
        {
            for(int j=1;j<y+1;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    t[i][j]=1+t[i-1][j-1];
                    mx=max(mx,t[i][j]);
                }
                else
                {
                    t[i][j]=0;
                }
            }
        }
        return mx;
    }
};