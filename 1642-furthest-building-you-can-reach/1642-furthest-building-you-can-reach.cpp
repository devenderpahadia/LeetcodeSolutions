class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int i =1;
        int n = heights.size();
        priority_queue<int>maxh;
        for(;i<n;i++){
            if(heights[i-1]>=heights[i]){
                continue;
            }
            else{
                bricks-=(heights[i]-heights[i-1]);
                maxh.push({heights[i]-heights[i-1]});
                
                if(bricks<0){
                    bricks+=maxh.top();
                    maxh.pop();
                    ladders--;
                }
                
                if(ladders<0)
                    break;
            }
        }
        return --i;
    }
};