class Solution {
public:
    string fractionToDecimal(int num, int den) {
        string res; 
        bool sign=false;
        if((num<0 && den>=0)|| (num>=0 && den<0)) sign=true;
    
        num=abs(num);
        den=abs(den);
        long long q=num/den;
        long long r=num%den;
        res+=to_string(q);
    
        if(sign==true && num!=0) res="-"+res;
    
        if(r==0){
            return res;
        }
        else{
            res+=".";
            map<int,int>m;
            while(r!=0)
            {
                if(m.count(r)==1)
                {
                    res=res.substr(0,m[r])+"("+res.substr(m[r])+")";
                    break;
                }
                else{
                    m[r]=res.length();
                    r=r*10;
                    q=r/den;
                    r=r%den;
                    res+=to_string(q);
                }
            }
        }
        return res;
    }
};