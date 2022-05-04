class Solution {
public:
    int countPairs(vector<int>& A) {
        vector<int> v(22);
        for(int i=0;i<22;i++) v[i]=pow(2,i);
        unordered_map<int,int> mp;
        int cnt=0,mod=1e9+7;
        for(auto &a:A){
            for(int i=0;i<22;i++){
                if(mp.count(v[i]-a)){
                    cnt=(cnt+mp[v[i]-a])%mod;
                }
            }
            mp[a]++;
        }
        return cnt;
    }
};