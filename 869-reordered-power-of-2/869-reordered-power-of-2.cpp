class Solution {
public:
    vector<int> solve(int n)
    {
        vector<int>res(10,0);
        while(n)
        {
            res[n%10]++;
            n/=10;
        }
        return res;
    }
    bool reorderedPowerOf2(int n) 
    {
        
        vector<int>given = solve(n);
        
        int x=1;
        while(x<1000000000)
        {
            vector<int>temp = solve(x);
            if(given == temp)
                return true;
            x*=2;
        }
        return false;
    }
};