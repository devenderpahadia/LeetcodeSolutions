class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        // int i=0;
        int ctr=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        
        for(int i=0;i<rocks.size();i++){
            if(capacity[i]-rocks[i]>0){
                minh.push({capacity[i]-rocks[i],i});
            }
        }
        
        while(minh.size()>0 && additionalRocks){
            int x = minh.top().first;
            int y = minh.top().second;
            if(additionalRocks-x >=0){
                // cout<<x<<endl<<y<<endl;
                rocks[y]+=(x);
                // cout<<rocks[y]<<endl;
                additionalRocks-=x;
                minh.pop();
            }
            else break;
        }
        
        for(int i=0;i<rocks.size();i++){
            if(rocks[i]==capacity[i]) ctr++;
        }
        return ctr;
    }
};