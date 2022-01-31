class Solution {
public:
    
    string solve(int n)
    {
        if(n==1)
            return "0";
        
        string res = solve(n-1);
        string str = res;
        
        for(int i=0;i<res.size();i++)
        {
            if(str[i]=='0')
            {
                str[i]='1';
            }
            else
            {
                str[i]='0';
            }
        }
        
        reverse(str.begin(),str.end());
        
        res+='1';
        res+=str;
        
        return res;
        
    }
    
    char findKthBit(int n, int k) {
        string res = solve(n);
        return res[k-1];
    }
};