// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void solve(int ind, vector < int > & arr, vector < int > & ans, int sum) {
      if (ind == arr.size()) {
        ans.push_back(sum);
        return;
      }
      //element is picked
      solve(ind + 1, arr,ans, sum + arr[ind]);
      //element is not picked
      solve(ind + 1, arr,ans, sum);
    }
  vector < int > subsetSums(vector < int > arr, int n) {
    vector < int > res;
    solve(0, arr, res, 0);
    return res;
  }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends