//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> t(n+1 , vector<int> (sum+1 , -1));
        
        return ans(arr, sum , n , t);
    }
    bool ans(vector<int> arr, int sum, int n , vector<vector<int>>& t)
    {
        //Base Condition
        if(sum == 0)return t[n][sum] = true;
        if(n == 0)return t[n][sum] = false;
        if(t[n][sum] != -1)return t[n][sum];
        if(arr[n-1] <= sum)
        {
            return t[n][sum] = (ans(arr, sum, n-1 , t) || ans(arr, sum - arr[n-1] , n-1 ,t ));
        }
        else
        {
            return t[n][sum] = ans(arr, sum, n-1 , t);
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends