class Solution {
public:
    int brokenCalc(int s, int t) {
        if(s>=t)
            return s-t;
        
        int l=INT_MAX,r=INT_MAX;
        
        if(t%2==0){
            l = 1+brokenCalc(s,t/2);
        }
        else{
            r = 1+brokenCalc(s,t+1);
        }
        
        return min(l,r);
    }
};