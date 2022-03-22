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
            if(k-sum>=26)
            {
                sum--;
                sum+=26;
                res[i]='z';
            }
            else
            {
                res[i] = ('a'+(k-sum));
                sum+=(k-sum);
            }
            i--;
        }
        return res;
    }
};