class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long mx = 0;
        unordered_map<int,long long>mp;
        for(int i=0;i<tasks.size();i++){
            if(mp.find(tasks[i])!=mp.end()){
                if(mx-mp[tasks[i]]>space){
                    mp[tasks[i]] = mx;
                }
                else{
                    mx+=(space-(mx-mp[tasks[i]])+1);
                    mp[tasks[i]] = mx;
                }
            }
            else{
                mp[tasks[i]]=mx;
            }
            mx++;
        }
        return mx;
    }
};