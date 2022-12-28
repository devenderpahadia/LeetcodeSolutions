class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto i:piles) pq.push(i);
        while(k--){
            int y=pq.top();
            int x=floor(y/2);
            pq.pop();
            pq.push(y-x);
        }
        int sum=0;
        while(pq.size()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};