class Solution {
public:
    double champagneTower(int p, int r, int g) {
        double arr[100][100] = {0.0};
        arr[0][0] = p;
        for(int i=0;i<99;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(arr[i][j]>=1)
                {
                    arr[i+1][j]+= (arr[i][j]-1) / 2.0;
                    arr[i+1][j+1]+= (arr[i][j]-1) / 2.0;
                    arr[i][j]=1.0;
                }
            }
        }
        return arr[r][g];
    }
};