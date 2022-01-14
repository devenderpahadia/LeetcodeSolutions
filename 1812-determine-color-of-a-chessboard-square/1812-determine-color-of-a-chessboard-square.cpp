class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int h = coordinates[0]-'a'+1;
        int r = coordinates[1]-'0';
        
        // if(h%2==1 && r%2==1) return false;
        // if(h%2==0 && r%2==1) return true;
        // if(h%2==1 && r%2==0) return true;
        // if(h%2==0 && r%2==1) return false;
        return (h%2)^(r%2);
    }
};