class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string res = "";
        int sum=n;
        while(n--)
        {
            res+='a';
        }
        int i=res.size()-1;
        while(sum<k)
        {
            // int idx = 0;
            for(int idx = 0; idx < 25; idx++){
                sum++;
                res[i]++;
                if(sum == k) break;
            }
            i--;
        }
        return res;
    }
};