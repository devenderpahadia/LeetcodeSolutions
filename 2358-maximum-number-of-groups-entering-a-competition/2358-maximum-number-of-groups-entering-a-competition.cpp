class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int sum = 0;
        int mx = 0;
        
        while(mx<=n){
            mx+= ++sum;
        }
        return sum-1;
        
    }
};