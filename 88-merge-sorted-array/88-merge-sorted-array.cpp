class Solution {
public:
    void merge(vector<int>& A, int n, vector<int>& B, int m) {
        // int solve(int A[],int n,int B[],int m){
        int i=n-1;
        int j=m-1;
        int k=m+n-1;

        while(i>=0 && j>=0){
                if(A[i]>B[j]){
                        A[k]=A[i];
                        k--;
                        i--;
                }
                else{
                        A[k]=B[j];
                        k--;
                        j--;
                }
        }
        while(i>=0){
        	A[k]=A[i];
                k--;
                i--;
        }
        while(j>=0){
        	A[k]=B[j];
                k--;
                j--;
        }
         // return A;
// }

    }
};