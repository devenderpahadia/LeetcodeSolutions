class Solution {
public:
    int longestValidParentheses(string s) {
        unordered_set<string>st;
        if(s.size()<=1) return 0;
        int ctr=0;
        
        int left=0,right=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                left++;
            }
            else{
                right++;
            }
            if(left==right){
                ctr = max(ctr,2*right);
            }
            else if(right>=left) {
                left=right=0;
            }
            
        }
        left=right=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='('){
                left++;
            }
            else{
                right++;
            }
            if(left==right){
                ctr = max(ctr,2*right);
            }
            else if(right<=left) {
                left=right=0;
            }
        }
        return ctr;
    }
};