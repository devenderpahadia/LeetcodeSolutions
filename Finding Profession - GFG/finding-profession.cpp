// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    char profession(int level, int pos){
        // code here
        if(level==1 || pos==1) return 'e';
        if(profession(level-1,(pos+1)/2)=='d')
            return pos%2==0 ? 'e' : 'd';
        return pos%2==0 ? 'd' : 'e';
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int level, pos;
        cin>>level>>pos;
        
        Solution ob;
        if(ob.profession(level, pos) == 'd')
            cout<<"Doctor\n";
        else
            cout<<"Engineer\n";
    }
    return 0;
}  // } Driver Code Ends