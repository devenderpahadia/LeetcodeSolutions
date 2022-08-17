class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>vec = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_map<char,string>mp;
        for(int i=0;i<vec.size();i++){
            mp[i+'a'] = vec[i];
        }
        unordered_set<string>st;
        for(auto it : words){
            string str ="";
            for(auto i : it){
                str+=(vec[i-'a']);
            }
            st.insert(str);
        }
        return st.size();
    }
};