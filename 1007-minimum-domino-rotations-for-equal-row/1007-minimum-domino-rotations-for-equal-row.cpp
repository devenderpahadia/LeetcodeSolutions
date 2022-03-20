class Solution {
public:
    
    int countdiff(vector<int>&tops, vector<int>&bottoms, int num)
    {
        int top=0,bottom=0;
        for(int i=0;i<tops.size();i++){
            
            if(tops[i]!=num && bottoms[i]!=num) 
                return -1;
            if(tops[i]!=num)
                top++;
            if(bottoms[i]!=num)
                bottom++;
        }
        return min(top,bottom);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int swap1 = countdiff(tops,bottoms,tops[0]);
        int swap2 = countdiff(tops,bottoms,bottoms[0]);
        return(min(swap1,swap2)<0)?max(swap1,swap2):min(swap1,swap2); 

    }
};