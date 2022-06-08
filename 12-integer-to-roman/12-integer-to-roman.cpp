class Solution {
public:
    string intToRoman(int num) {
        vector<int>rnums = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string>rstrs = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        string res = "";
        for(int i = rnums.size()-1;i>=0;i--){
            int div = num/rnums[i];
            num = num - (div*rnums[i]);
            while(div--){
                res+=rstrs[i];
            }
        }
        return res;
    }
};