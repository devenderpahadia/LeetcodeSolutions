class Solution {
public:
    
    bool solve(string s,int l,int h)
    {
        while(l<=h && s[l]==s[h])
        {
            l++;
            h--;
        }
        
        return l>h;
    }
    
    bool validPalindrome(string s) {
        int l=0;
        int h=s.size()-1;
        
        while(l<=h && s[l]==s[h])
        {
            l++;
            h--;
        }
        
        if(l>h)
            return true;
        
        return solve(s,l+1,h) || solve(s,l,h-1);
    }
};