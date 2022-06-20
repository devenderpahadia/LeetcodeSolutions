bool compare(string &s1,string &s2)
{
    return s1.size() > s2.size();
}

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        int n = words.size();
        string str=words[0];
        str+='#';
        for(int i=1;i<n;i++){
            string temp = words[i];
            temp+='#';
            if(str.find(temp)!=string::npos){
                continue;
            }
            else{
                str+=temp;
            }
        }
        // cout<<str<<endl;
        return str.size();
    }
};