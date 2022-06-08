class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        stack<int>st;
        for(int i=0;i<bank.size();i++){
            int ctr = 0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1') ctr++;
            }
            if(ctr!=0)
            st.push(ctr);
        }
        if(st.size()==0 || st.size()==1) return 0;
        int sum = 0;
        int x = st.top();
        st.pop();
        while(st.size()){
            sum += (x*st.top());
            x = st.top();
            st.pop();
        }
        return sum;
    }
};