class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int>arr(100002);
        vector<int>res;
        for(auto it : nums){
            if(it<0){
                arr[it+100001]++;
            }
            else{
                arr[it]++;
            }
        }
        for(int i=50001;i<100002;i++){
            while(arr[i]--){
                res.push_back(i-100001);
            }
        }
        for(int i=0;i<=50000;i++){
            while(arr[i]--){
                res.push_back(i);
            }
        }
        return res;
    }
};