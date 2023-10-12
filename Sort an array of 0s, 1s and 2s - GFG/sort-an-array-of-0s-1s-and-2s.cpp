//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int low = 0;
        int mid = 0;
        int high = n-1;
        while(low<=high && mid<=high){
            if(a[mid] == 0){
                swap(a[low],a[mid]);
                low += 1;
                mid += 1;
            }
            else if(a[mid] == 1){
                mid = mid + 1;
            }
            else{
                swap(a[mid],a[high]);
                high = high-1;
            }
        }
    }
    
    
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends