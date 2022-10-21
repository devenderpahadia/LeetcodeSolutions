class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int>st;
        int mx = -1;
        for(auto it : nums){
            if(st.find(-1*it)!=st.end()){
                cout<<-1*it<<endl;
                mx = max({mx,it,-1*it});
            }
            st.insert(it);
        }
        return mx;
    }
};