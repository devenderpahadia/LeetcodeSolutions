class Solution {
public:
    int solve(string s,int i,int j){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }
        return j-i-1;
    }
    
    string longestPalindrome(string s) {
        if(s.size()<1) return "";
        int start = 0;
        int end = 0;
        for(int i=0;i<s.size();i++){
            int len1 = solve(s,i,i+1); //even paildrome
            int len2 = solve(s,i,i); //odd palindrome
            int len = max(len1,len2);
            if(end-start< len )
            {
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }
        return s.substr(start,end-start+1);
    }
};