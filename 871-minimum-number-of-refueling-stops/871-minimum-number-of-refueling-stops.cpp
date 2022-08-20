class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int curr = startFuel;
        int i=0;
        int res = 0;
        priority_queue<int>maxh;
        int n = stations.size();
        while(curr<target){
            while(i<n && curr>=stations[i][0]){
                maxh.push(stations[i][1]);
                i++;
            }
            if(maxh.size()==0) return -1;
            curr+=maxh.top();
            maxh.pop();
            res++;
        }
        return res;
    }
};