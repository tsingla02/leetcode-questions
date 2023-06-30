//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    if ( m == 1)return 1;
	    if(n> m)return -1;
	    int mid = m / 2;
	    int start = 1;
	    int end = m;
	    while(start<= end)
	    {
	        mid = start + (end-start)/2;
	        if(pow(mid, n) == m)return mid;
	        else if(pow(mid, n) > m)
	        {
	            end = mid-1;
	        }
	        else
	        {
	            start = mid + 1;
	        }
	    }
	    if(pow(mid,n) == m)return mid;
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends