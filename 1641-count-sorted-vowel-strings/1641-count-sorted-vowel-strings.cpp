class Solution {
public:
    
    int solve(string str,int i,int k,int n)
    {
        if(k==n)
        {
            return 1;
        }
        int ctr=0;
        for(int j=i;j<5;j++)
        {
            ctr+=solve(str,j,k+1,n);
        }
        return ctr;
    }
    
    int countVowelStrings(int n) {
        string str = "aeiou";
        int ctr = 0;
        for(int i=0;i<5;i++){
            ctr+=solve(str,i,1,n);
        }
        return ctr;
    }
};