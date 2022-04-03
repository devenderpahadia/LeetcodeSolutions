class Solution {
public:
    unordered_map<int,int>mp;
    int integerReplacement(int n) {
        
        if(n==2147483647)
            return 32;
        
        if(n==1)
            return 0;
        int l = INT_MAX,r=INT_MAX;
        if(n%2==0)
        {
            if(mp.find(n/2)!=mp.end())
                l = mp[n/2];
            else{
                l = 1+integerReplacement(n/2);
                mp[n/2] = l;
            }
        }
        else
        {
            if(mp.find(n-1)!=mp.end())
                l = mp[n-1];
            else{
                l = 1+integerReplacement(n-1);
                mp[n-1] = l;
            }
            if(mp.find(n+1)!=mp.end())
                r = mp[n+1];
            else{
                r = 1+integerReplacement(n+1);
                mp[n+1] = r;
            }
        }
        return mp[n] = min(l,r);
    }
};