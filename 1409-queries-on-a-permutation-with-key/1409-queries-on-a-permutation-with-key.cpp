class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int>P(m);
        for(int i=0;i<m;i++){
            P[i] = i+1;
        }
        vector<int>res;
        for(auto it : queries){
            int x = find(P.begin(), P.end(), it) - P.begin();
            res.push_back(x);
            P.erase(P.begin()+x);
            P.insert(P.begin()+0,it);
        }
        return res;
    }
};