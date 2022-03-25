bool comparator(vector<int>a,vector<int>b)
    {
        if(a[0]-a[1] < b[0]-b[1]) return true;
        return false;
    }
    
class Solution {
public:
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),comparator);
        int sum = 0;
        for(int i=0;i<costs.size()/2;i++)
        {
            sum+=(costs[i][0]);
        }
        for(int i=costs.size()-1;i>=costs.size()/2;i--)
        {
            sum+=(costs[i][1]);
        }
        return sum;
    }
};