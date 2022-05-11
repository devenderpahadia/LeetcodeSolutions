class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        double res = 1;
        for(int i=1;i<=m-1;i++)
        {
            res = res*(N+i-m+1)/i;
            // N--;
        }
        return (int)(res);
    }
};