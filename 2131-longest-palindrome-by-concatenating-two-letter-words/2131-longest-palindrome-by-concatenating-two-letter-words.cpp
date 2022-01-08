class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        for(auto it : words)
        {
            mp[it]++;
        }
        int ctr=0;
        bool flag  = false;
        int mx=0;
        
        for(auto it : words)
        {
            string temp = it;
            reverse(temp.begin(),temp.end());
            if(temp!=it && mp[temp]>0 && mp[it]>0)
            {
                ctr+=4;
                mp[temp]--;
                mp[it]--;
            }
            else if(temp==it && mp[it]>1)
            {
                mp[it]-=2;
                ctr+=4;
            }
            else if(temp==it && !flag && mp[it]>0)
            {
                mp[it]--;
                flag=true;
                ctr+=2;
            }
        }
        
        return ctr;
    }
};