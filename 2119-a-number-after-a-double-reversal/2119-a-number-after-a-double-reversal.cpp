class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num==0)
            return true;
        string str = to_string(num);
        
        
        return str[str.size()-1]!='0';
    }
};