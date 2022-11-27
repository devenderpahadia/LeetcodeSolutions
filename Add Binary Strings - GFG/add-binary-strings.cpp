//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b)
	{
	    // your code here
	    string res;

        int i = a.length() - 1;

        int j = b.length() - 1;

        int carry = 0;

        while(i >= 0 || j >= 0){

            int sum = carry;

            if(i >= 0) sum += a[i--] - '0';

            if(j >= 0) sum += b[j--] - '0';

            carry = sum > 1 ? 1 : 0;

            res += to_string(sum % 2);

        }

        if(carry) res += to_string(carry);

        reverse(res.begin(), res.end());

        i = 0;

     while(res[i] == '0')

     {

         res.erase(0, 1);

     }

  

        return res;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends