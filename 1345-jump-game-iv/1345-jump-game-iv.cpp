class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1)
            return 0;
        if(n==2)
            return 1;
        
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]].push_back(i);
        }
        
        int step=0;
        queue<int>q;
        q.push(0);
        
        while(!q.empty())
        {
            step++;
            int sz = q.size();
            while(sz--)
            {
                int i = q.front();
                q.pop();
                
                if(i-1 >= 0 && mp.find(arr[i-1])!=mp.end())
                {
                    q.push(i-1);
                }
                
                if(i+1 < n && mp.find(arr[i+1])!=mp.end())
                {
                    if(i+1 == n-1)
                        return step;
                    q.push(i+1);
                }
                
                if(mp.find(arr[i])!=mp.end())
                {
                    for(auto k : mp[arr[i]])
                    {
                        if(k!=i)
                        {
                            if(k==n-1) return step;
                            q.push(k);
                        }
                        
                    }
                }
                
                mp.erase(arr[i]);
                
            }
            
        }
        return step;
            
    }
};