class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ctr = 1;
        int mx = capacity;
        for(int i=0;i<plants.size()-1;i++){
            mx = mx-plants[i];
            if(mx>=plants[i+1]){
                ctr++;
            }
            else{
                ctr+=(i+1);
                mx = capacity;
                ctr+=(i+2);
            }
        }
        return ctr;
    }
};