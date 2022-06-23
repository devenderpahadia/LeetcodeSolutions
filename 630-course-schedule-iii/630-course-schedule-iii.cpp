class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        for(auto it : courses){
            minh.push({it[1],it[0]});
        }
        priority_queue<int>maxh;
        int ctr=0;
        // int res = 0;
        while(minh.size()){
            if(ctr+minh.top().second <= minh.top().first){
                // res++;
                ctr+=minh.top().second;
                maxh.push(minh.top().second);
            }
            else if(maxh.size() && maxh.top()>=minh.top().second){
                ctr-=maxh.top();
                ctr+=minh.top().second;
                maxh.pop();
                maxh.push(minh.top().second);
            }
            minh.pop();
        }
        return maxh.size();
    }
};