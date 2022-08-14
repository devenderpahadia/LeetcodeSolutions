class Solution {
public:
    int edgeScore(vector<int>& edges) {
        long long n = edges.size();
        vector<long long>score(n);
        
        for(long long i=0;i<n;i++){
            score[edges[i]]+=i;
        }
        long long mx = -1;
        long long k;
        for(long long i=0;i<score.size();i++){
            if(score[i]>mx){
                mx = score[i];
                k=i;
            }
        }
        return k;
    }
};