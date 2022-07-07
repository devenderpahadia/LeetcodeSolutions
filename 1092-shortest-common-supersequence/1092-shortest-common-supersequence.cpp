class Solution {
public:
    int t[1001][1001];
    void lcs (string a, string b, int n, int m)
    {
        for(int i=0;i<n+1;i++)
            t[i][0]=0;
        for(int i=0;i<m+1;i++)
            t[0][i]=0;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(a[i-1]==b[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    string shortestCommonSupersequence(string a, string b) {
        int i=a.length();
        int j=b.length();
        lcs(a,b,i,j);
        string res="";
        while(i>0&&j>0)
        {
            if(a[i-1]==b[j-1])
            {
                res+=a[i-1];
                i--;
                j--;
            }
            else
                if(t[i][j-1]>t[i-1][j])
                {
                    res+=b[j-1];
                    j--;
                }
            else 
                {
                    res+=a[i-1];
                    i--;
                }
                
        }
        while(i>0)
        {
            res+=a[i-1];
            i--;
        }
        while(j>0)
        {
            res+=b[j-1];
            j--;
        }
        reverse(res.begin(),res.end());
        return res;        
    }
};