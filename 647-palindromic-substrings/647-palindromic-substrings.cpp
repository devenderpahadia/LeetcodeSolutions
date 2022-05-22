class Solution {
public:
    bool safe(string str,int i,int j){
        while(i<=j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int ctr=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(safe(s,i,j)){
                    ctr++;
                }
            }
        }
        return ctr;
    }
};