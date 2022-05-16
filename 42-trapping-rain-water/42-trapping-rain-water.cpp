class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n=height.size();
        if(n==0)
            return 0;
        int left = 0,right = 0;
        int res = 0;
        int l = 0,h = n-1;
        while(l<=h)
        {
            if(height[l]<=height[h]){
                if(height[l]>=left) left = height[l];
                else res+=(left - height[l]);
                l++;
            }
            else{
                if(height[h]>=right) right = height[h];
                else res+=(right-height[h]);
                h--;
            }
        }
        return res;
    }
};