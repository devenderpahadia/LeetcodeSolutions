class Solution {
public:
    string longest = "";

    void findPalindrome(int start, int end, string s){
        while(start>=0 && end<s.length() && s[start]==s[end]){
            start--;
            end++;
        }
        start++;
        end--;
        if(start<=end){
            string temp = s.substr(start, end-start+1);
            if(temp.length()>longest.length()){
                longest = temp;
            }
        }
    }

    string longestPalindrome(string s) {
        if(s.length()==1){
            return s;
        }
        else if(s[0]!=s[1]&&s.length()==2){
            string temp(1, s[0]);
            return temp;
        }
        for(int i=0; i<s.length(); i++){
            if(s[i]==s[i+1]&&i+1<s.length()){
                findPalindrome(i,i+1,s);
            }
            if(i+2<s.length()&&s[i]==s[i+2]){
                findPalindrome(i,i+2,s);
            }
        }
        if(longest.compare("")==0){
            string temp(1, s[0]);
            return temp;
        }
        return longest;
    }
};