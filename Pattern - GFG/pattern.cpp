//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printfirst(int n){
        for(int i=0;i<n;i++){
           for(int j=0;j < n-i-1;j++){
               cout<<" ";
           }
           for(int j=0;j < i+1 ;j++){
               cout<<"* ";
           }
        //   for(int j=n;j < n-i-1;j--){
        //       cout<<" ";
        //   }
           cout<<endl;
       }
    }
    void printlast(int n){
        for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            cout<<" ";
	        }
	        for(int j=0;j<=n-i-1;j++){
                cout<<"* ";
            }
            // for(int j=n;j<i;j--){
            //     cout<<" ";
            // }
            cout<<endl;
        }
    }
    void printDiamond(int n) {
        printfirst(n);
        printlast(n);
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
        ob.printDiamond(n);
    }
    return 0;
}
// } Driver Code Ends