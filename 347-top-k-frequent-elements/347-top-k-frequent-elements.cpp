class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int>H;
        for(int i=0;i<nums.size();i++)
        {
            H[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        for(auto it : H)
        {
            minh.push({it.second,it.first});
            if(minh.size()>k)
                minh.pop();
        }
        
        vector<int>res;
        while(minh.size()>0)
        {
            res.push_back(minh.top().second);
            minh.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};