class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) 
    {
        vector<int>res;
        int n=changed.size();
        if(n%2 == 1)
            return res;
        unordered_map<int,int>mp;
        sort(changed.begin(),changed.end());
        int ctr=0;
        for(int i=0;i<n;i++)
        {
            mp[changed[i]]++;
            if(changed[i]==0)
                ctr++;
        }
        if(ctr%2==1) return {};
        for(int i=0;i<changed.size();i++)
        {
            if(mp[changed[i]] && mp[2*changed[i]])
            {
                mp[2*changed[i]]--;
                mp[changed[i]]--;
                res.push_back(changed[i]);
            }      
        }
        if(res.size()!=n/2)
            return {};
        return res;
    }
};