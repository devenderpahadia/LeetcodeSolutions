class Solution {
public:
    int myAtoi(string s) {
        if (s=="")
            return 0;
        int num = 0, positive=1, i=0;
        int n = s.size();
        while(i<n && s[i]==' ')
            i++;
        if (s[i]=='-'){
            positive=0;
            i++;            
        }
        else if (s[i]=='+')
            i++;
        while(i<n && s[i]>='0'&& s[i]<='9'){
            num = num*10 + (s[i]-'0');
            i++;
            if (!(s[i]>='0'&& s[i]<='9'))
                break;
            if (i<n && INT_MAX/10<=num){
                if (i==n-1 && INT_MAX/10==num && s[i]<'8')
                    continue;
                return positive==1?INT_MAX:INT_MIN;
            }
        }   
        return positive==1?num:num*-1;
    }
};