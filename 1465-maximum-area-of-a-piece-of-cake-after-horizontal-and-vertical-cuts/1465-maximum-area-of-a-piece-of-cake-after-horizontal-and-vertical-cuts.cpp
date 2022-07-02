#define mod 1000000007
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {
        hC.push_back(h);
        vC.push_back(w);
        
        sort(hC.begin(),hC.end());
        sort(vC.begin(),vC.end());
        
        int mh = hC[0];
        int mc = vC[0];
        
        for(int i=1;i<hC.size();i++){
            mh = max(mh,hC[i]-hC[i-1]);
        }
        for(int i=1;i<vC.size();i++){
            mc = max(mc,vC[i]-vC[i-1]);
        }
        
        return (1LL*mh*mc)%mod;
        
    }
};