class Solution {
public:
    void solve(int idx,vector<int> &s,vector<vector<int>>&res){
	if(idx==s.size()){
		res.push_back(s);
		return;
	}
	for(int i=idx;i<s.size();i++){
		swap(s[idx],s[i]);
		solve(idx+1,s,res);
		swap(s[idx],s[i]);
	}
}
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
	    solve(0,nums,res);
	    return res;
    }
};