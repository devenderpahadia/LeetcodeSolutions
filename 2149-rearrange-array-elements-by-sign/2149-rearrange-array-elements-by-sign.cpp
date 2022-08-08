class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        for(auto it : nums){
            if(it>=0){
                pos.push_back(it);
            }
            else{
                neg.push_back(it);
            }
        }
        vector<int>res;
        for(int i=0;i<pos.size();i++){
            res.push_back(pos[i]);
            res.push_back(neg[i]);
        }
        return res;
    }
};