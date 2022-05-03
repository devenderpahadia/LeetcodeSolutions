class Solution {
public:
    void solve(vector<int>&ip,int k,int p,set<vector<int>>&st)
    {
        for(int i=0;i<ip.size();i++)
        {
            vector<int>temp;
            int ctr=0;
            for(int j=i;j<ip.size() ;j++)
            {
                temp.push_back(ip[j]);
                if(ip[j]%p == 0)
                    ctr++;
                if(ctr>k)
                    break;
                st.insert(temp);
            }
        }
    }
    
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int> >st;
        solve(nums,k,p,st);
        return st.size();
    }
};