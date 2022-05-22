// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
        // code here
        string res = "";
        int j=0;
        for(int i=0;i<S.size();){
            if(index[j]==i){
                int x = 0;
                int flag = 1;
                for(int k=i;k<S.size() && x<sources[j].size();k++,x++){
                    if(sources[j][x]!=S[k]){
                        flag= 0;
                        break;
                    }
                }
                if(flag){
                    res+=targets[j];
                    i+=(sources[j].size());
                    // i--;
                }
                else{
                    for(int k=i;k<sources[j].size();k++){
                        res+=S[k];
                        i++;
                    }
                    // i--;
                }
                j++;
            }
            else{
                res+=S[i];
                i++;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends