class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int l = 1;
        int h = piles.size()-2;
        int n = piles.size();
        int sum = 0;
        for(int i = h;i>=0 && l<=n/3;i-=2){
            sum+=piles[i];
            l++;
        }
        return sum;
    }
};