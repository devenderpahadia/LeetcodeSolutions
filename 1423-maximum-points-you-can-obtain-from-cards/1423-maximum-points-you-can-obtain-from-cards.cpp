class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int mx = INT_MAX;
        int n = cardPoints.size();
        int summ = 0;
        int i = 0;
        int j = 0;
        int sum = 0;
        while(j<n){
            sum+=cardPoints[j];
            if(j-i+1 == n-k){
                mx = min(mx,sum);
                sum-=cardPoints[i];
                i++;
            }
            summ+=cardPoints[j];
            j++;
        }
        if(k==n) return summ;
        return summ - mx;
    }
};