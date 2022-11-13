class Solution {
public:
    string reverseWords(string s) {
        vector<string>vec;
        stringstream checks(s);
        string temp;
        while(getline(checks,temp,' ')){
            vec.push_back(temp);
        }
        reverse(vec.begin(),vec.end());
        string res = "";
        for(auto it : vec){
            res+=it;
            res.push_back(' ');
        }
        res.pop_back();
        for(int i=1;i<res.size();){
            if(res[i-1]==' ' && res[i]==' '){
                res.erase(res.begin()+i);
            }
            else i++;
        }
        if(res[0]==' ') res.erase(res.begin());
        if(res[res.size()-1]==' ') res.erase(res.begin()+res.size()-1);        
        return res;
    }
};