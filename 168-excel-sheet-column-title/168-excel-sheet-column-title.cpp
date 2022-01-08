class Solution {
public:
    string convertToTitle(int n) 
    {
        string str ;
        while(n)
        {
            str+= 'A' + ((n-1)%26);
            n = (n-1)/26;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};