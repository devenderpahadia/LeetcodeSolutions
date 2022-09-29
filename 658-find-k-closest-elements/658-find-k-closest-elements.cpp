class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>res;
        priority_queue<pair<int,int>>minh;
        for(auto it : arr){
            minh.push({abs(it-x),it});
            if(minh.size()>k) minh.pop();
        }
        while(minh.size()){
            res.push_back(minh.top().second);
            minh.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};