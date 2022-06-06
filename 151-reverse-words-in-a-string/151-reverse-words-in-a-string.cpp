class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string temp = "";
        int n = s.size()-1;
        int i;
        for(i=0;i<=n;i++){
            if(s[i]==' ' ){
                
                if(temp!=""){
                    if(res=="") res = temp;
                    else res = temp + " " + res;
                    temp="";
                }
            }
            else{
                temp+=s[i];
            }
        }
        if(temp.size()){
            if(res=="") res = temp;
                else res = temp + " " + res;
                temp="";
        }
        return res;
    }
};