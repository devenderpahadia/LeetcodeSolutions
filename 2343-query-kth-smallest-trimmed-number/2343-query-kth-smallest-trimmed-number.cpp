class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>res;
        for(auto i:queries){
            int ki = i[0];
            int ti = i[1];
            priority_queue<pair<string,int>>maxh;
            int k = 0;
            for(auto it : nums){
                string s = it.substr(nums[0].size()-ti);
                maxh.push({s,k});
                if(maxh.size()>ki) maxh.pop();
                k++;
            }
            res.push_back(maxh.top().second);
        }
        return res;
    }
};