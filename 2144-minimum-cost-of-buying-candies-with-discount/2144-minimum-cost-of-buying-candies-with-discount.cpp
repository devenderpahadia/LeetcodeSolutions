class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int sum=0;
        if(cost.size()<=2)
        {
            for(auto it : cost)
                sum+=it;
            return sum;
        }
        sort(cost.begin(),cost.end());
        int i=cost.size()-1;
        
        while(i>=0)
        {
            if(i>=0)
            sum+=cost[i];
            i--;
            if(i>=0)
            sum+=cost[i];
            i-=2;
        }
        return sum;
    }
};