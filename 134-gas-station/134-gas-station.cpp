class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr=0;
        int total=0;
        int res = 0;
        for(int i=0;i<gas.size();i++)
        {
            total+=(gas[i]-cost[i]);
            curr+=(gas[i]-cost[i]);
            if(curr<0)
            {
                curr=0;
                res=i+1;
            }
        }
        return total<0 ? -1 : res;
    }
};