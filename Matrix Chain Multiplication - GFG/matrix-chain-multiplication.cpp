//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int arr[], int n , int i , int j,vector<vector<int>> &dp)
    {
        if(i>=j){
            return 0;
        }
        if(dp[i][j] != -1)return dp[i][j];
        int mn = INT_MAX;
        for(int k = i ; k < j ; k++)
        {
            int temp_ans = solve(arr, n, i, k,dp) + solve(arr,n,k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
            mn = min(mn , temp_ans);
        }
        return dp[i][j] = mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N+1, vector<int>(N+1,-1));
        return solve(arr,N,1,N-1,dp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends