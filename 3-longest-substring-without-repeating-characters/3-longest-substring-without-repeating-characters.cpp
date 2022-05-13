class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l = 0,r=0;
        int mx = 0;
        while(r<s.size())
        {
            if(mp.find(s[r])!=mp.end())
                l = max(mp[s[r]]+1,l);
            
                mp[s[r]]=r;
                mx = max(mx,r-l+1);
                r++;
        }
        return mx;
    }
};