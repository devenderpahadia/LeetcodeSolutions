class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n=s.size();
        int i=0;
        int j=0;
        unordered_map<char,int>mp;
        
        int mx=0;
        while(j<n)
        {
            mp[s[j]]++;
            if(j-i+1 == mp.size())
            {
                if(mp.size()>mx)
                {
                    mx=mp.size();
                }
                j++;
            }
            else
            {
                while(mp.size()< j-i+1)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
    
};