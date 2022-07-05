class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ctr=0;
        int x = 0;
        for(int i=0;i<arr.size()-1;i++){
            x^=arr[i];
            for(int j=i+1;j<arr.size();j++){
                x^=arr[j];
                if(x==0) ctr+=(j-i);
            }
            x=0;
        }
        return ctr;
    }
};