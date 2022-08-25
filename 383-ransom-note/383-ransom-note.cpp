class Solution {
public:
    bool canConstruct(string str1, string str2) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(auto it : str1) mp1[it]++;
        for(auto it : str2) mp2[it]++;
        for(auto it : str1){
            if( mp2.count(it) && mp2[it]>=mp1[it]) {}
            else
            return false;
        }
        return true;
    }
};