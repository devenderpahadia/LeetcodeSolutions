#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        ordered_set P;
        vector<int>res;
        for(int i=nums.size()-1;i>=0;i--){
            P.insert(nums[i]);
            res.push_back(P.order_of_key(nums[i]));
        }
        reverse(res.begin(),res.end());
        return res;
    }
};