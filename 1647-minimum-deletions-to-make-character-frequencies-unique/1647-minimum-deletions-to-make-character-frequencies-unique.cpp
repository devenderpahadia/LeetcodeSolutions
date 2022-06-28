class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        int mx = INT_MAX;
        for(auto it : s){
            mp[it]++;
        }
        unordered_map<int,int>mp1;
        priority_queue<pair<int,char>>maxh;
        for(auto it : mp){
            maxh.push({it.second,it.first});
        }
        int sum = 0;
        
        while(maxh.size()){
            if(maxh.top().first==0) maxh.pop();
            else if(mp1.find(maxh.top().first)!=mp1.end()){
                auto it = maxh.top();
                maxh.pop();
                sum++;
                maxh.push({it.first-1,it.second});
            }
            else{
                mp1[maxh.top().first]++;
                maxh.pop();
            }
        }
        
        
        return sum;
    }
};