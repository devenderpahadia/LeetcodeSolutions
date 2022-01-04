class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx=-1;
        for(auto it : candies)
            mx = max(mx,it);
        
        vector<bool>res(candies.size());
        
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]+extraCandies >=mx)
                res[i]=true;
            else
                res[i]=false;
        }
        return res;
    }
};