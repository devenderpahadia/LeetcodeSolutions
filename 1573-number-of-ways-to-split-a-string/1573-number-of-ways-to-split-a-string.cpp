#define mod 1000000007

class Solution {
public:
    int numWays(string s) {
        int ctr=0;
        long long n = s.size();
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') ctr++;
        }
        if(ctr%3!=0) return 0;
        if(ctr==0) return ((n-1)*(n-2)/2)%mod;
        ctr = ctr/3;
        vector<int>arr(4);
        int i,j=0;
        int t = 0;
        for(i=0;i<s.size();i++){
            if(s[i]=='1') t++;
            if(t==ctr){
                arr[0] = i;
                i++;
                break;
            }
        }
        for(;i<s.size();i++){
            if(s[i]=='1') {
                arr[1] = i;
                break;
            }
        }
        t=0;
        for(i=s.size()-1;i>=0;i--){
            if(s[i]=='1') t++;
            if(t==ctr){
                arr[3] = i;
                i--;
                break;
            }
        }
        for(;i>=0;i--){
            if(s[i]=='1') {
                arr[2] = i;
                break;
            }
        }
        
        // cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<endl;
        
        return ((long long)(arr[1]-arr[0])*(long long)(arr[3]-arr[2]))%mod;
    }
};