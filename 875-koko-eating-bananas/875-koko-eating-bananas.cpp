class Solution {
public:
    
    bool solve(vector<int> piles, int m,int h)
    {
        int ctr=0;
        for(int i=0;i<piles.size();i++)
        {
            
            ctr+=(piles[i]/m)+(piles[i]%m!=0);
            if(ctr>h)
            {
                return false;
            }
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int k) {
        int l = 1;
        int h = *max_element(piles.begin(), piles.end());
        
        while(l<h)
        {
            int mid = l + (h-l)/2;
            if(solve(piles,mid,k)==true)
            {
                h=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};