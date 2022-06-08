class Solution {
public:
    
    int solve(char c){
        if(c=='I') return 1;
        if(c=='V') return 5;
        if(c=='X') return 10;
        if(c=='L') return 50;
        if(c=='C') return 100;
        if(c=='D') return 500;
        if(c=='M') return 1000;
        return 1;
    }
    
    int romanToInt(string s) {
        if(s.size()==1) return solve(s[0]);
        int sum = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='I' && s[i+1]=='V'){
                sum+=4;
                i++;
            }
            else if(s[i]=='I' && s[i+1]=='X'){
                sum+=9;
                i++;
            }
            else if(s[i]=='X' && s[i+1]=='L'){
                sum+=40;
                i++;
            }
            else if(s[i]=='X' && s[i+1]=='C'){
                sum+=90;
                i++;
            }
            else if(s[i]=='C' && s[i+1]=='D'){
                sum+=400;
                i++;
            }
            else if(s[i]=='C' && s[i+1]=='M'){
                sum+=900;
                i++;
            }
            else{
                sum+=solve(s[i]);
            }
        }
        return sum;
    }
};