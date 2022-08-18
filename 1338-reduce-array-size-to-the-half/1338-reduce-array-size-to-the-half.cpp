class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto it : arr){
            mp[it]++;
        }
        vector<int>vec;
        for(auto it : mp){
            vec.push_back(it.second);
        }
        sort(vec.rbegin(),vec.rend());
        int sum = 0;
        int ctr=0;
        for(int i=0;i<vec.size();i++){
            sum+=vec[i];
            ctr++;
            if(sum>=arr.size()/2){
                return ctr;
            }
        }
        return ctr;
    }
};