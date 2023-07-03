//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        char a = 64+n;
        string s;
        while(a != 64)
        {
            s.push_back(a);
            for(int i = 0 ; i< s.size() ; i++)
            {
                cout<<s[i]<<" ";
            }
            cout<<endl;
            a--;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends