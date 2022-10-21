class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int>st;
        for(auto it : nums){
            st.insert(it);
            int x = it;
            int n = 0;
            while(x){
                n=n*10;
                n+=(x%10);
                x/=10;
            }
            st.insert(n);
        }
        return st.size();
    }
};