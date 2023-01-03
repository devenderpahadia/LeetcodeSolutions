class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ctr=0;
        for(int j=0;j<strs[0].size();j++){
            for(int i=0;i<strs.size()-1;i++){
                if(strs[i][j]>strs[i+1][j]){
                    ctr++;
                    break;
                }
            }
        }
        return ctr;
    }
};