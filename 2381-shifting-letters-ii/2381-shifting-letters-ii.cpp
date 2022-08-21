class Solution {
public:
    void add(vector<int>&arr, int N, int lo, int hi, int val)
    {
        arr[lo] += val;
        if (hi != N - 1)
           arr[hi + 1] -= val;
    }
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n = s.size();
        vector<int>vec(n);
        
        for(auto it : shifts){
            int l = it[0];
            int r = it[1];
            int dir = it[2];
            if(dir==0) dir=-1;
            add(vec,n,l,r,dir);
        }
        for(int i=1;i<n;i++){
            vec[i]+=vec[i-1];
        }
        
        string str = "abcdefghijklmnopqrstuvwxyz";
        for(int i=0;i<n;i++){
            
            if(vec[i]<0){
                // cout<<vec[i]<<endl;
                char c = s[i];
                // cout<<c<<endl;
                long long x = abs(vec[i])%26;
                long long y = vec[i] + (x+50000)*26;
                s[i] = str[((s[i]-'a')+y)%26];
                // cout<<s[i]<<endl;
            }
            else
            s[i] = str[((s[i]-'a')+vec[i])%26];
        }
        
        
        return s;
    }
};