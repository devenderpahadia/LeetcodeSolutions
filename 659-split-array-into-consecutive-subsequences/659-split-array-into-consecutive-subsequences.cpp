class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it : nums) mp[it]++;
        unordered_map<int,int>mp1;
        for(auto it : nums){
            if(mp[it]==0) continue;
            
            if(mp1[it]>0){
                mp[it]--;
                mp1[it]--;
                mp1[it+1]++;
            }
            else if(mp[it]>0 && mp[it+1]>0 && mp[it+2]>0){
                mp[it]--;
                mp[it+1]--;
                mp[it+2]--;
                
                mp1[it+3]++;
            }
            else return false;
        }
        return true;
    }
};