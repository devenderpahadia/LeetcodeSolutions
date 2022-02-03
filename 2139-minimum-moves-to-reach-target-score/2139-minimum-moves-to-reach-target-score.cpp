class Solution {
    map<pair<int,int>,int>mp;
    
    public:
    int minMoves(int target, int maxDoubles) {
        if(target == 1)
        {
            return 0;
        }
        if(target%2==1 && maxDoubles==0) return target-1;
        if(target%2==0 && maxDoubles>0)
        {
            return 1 + minMoves(target/2,maxDoubles-1);
        }
        else
        return 1 + minMoves(target-1,maxDoubles);
    }
};