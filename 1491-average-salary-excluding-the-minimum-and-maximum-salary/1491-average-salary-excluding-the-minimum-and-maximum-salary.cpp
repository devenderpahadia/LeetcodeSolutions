class Solution {
public:
    double average(vector<int>& salary) {
        double sum=0;
        for(auto it : salary)
        {
            sum+=it;
        }
        sort(salary.begin(),salary.end());
        sum-=salary[0];
        sum-=salary[salary.size()-1];
        return sum/(salary.size()-2);
    }
};