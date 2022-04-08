class Solution {
public:
    
    int getMaximumGenerated(int n) {
        if(n==0)
            return 0;
        int mx = 1;
        vector<int>vec(n+1,0);
        vec[0]=0;
        vec[1]=1;
        for(int k=2;k<=n;k++)
        {
            // cout<<"dev";
            if(k%2==0)
                vec[k] = vec[k/2];
            else
            {
                vec[k] = vec[k/2] + vec[k/2 +1];
            }
            mx = max({vec[k],mx});
        }
        return mx;
    }
};