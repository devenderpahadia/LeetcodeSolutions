// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        unordered_map<char,int>st;
        unordered_map<char,int>temp;
        for(auto it : str) st[it]++;
        
        int i=0,j=0;
        int n = str.size();
        int ctr = INT_MAX;
        
        while(j<n){
            temp[str[j]]++;
            while(temp.size()==st.size() ){
                ctr = min(ctr,j-i+1);
                temp[str[i]]--;
                // cout<<str[i]<<" "<<temp[str[i]]<<" ";
                if(temp[str[i]]==0) temp.erase(str[i]);
                // cout<<temp.size()<<endl;
                i++;
            }
            j++;
        }
        // if(temp.size()==st.size() ){
        //     i++;
        //     ctr = min(ctr,j-i+1);
        // }
        return ctr;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends