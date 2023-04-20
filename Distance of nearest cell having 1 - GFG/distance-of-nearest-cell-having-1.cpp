//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size() ; 
	    int m = grid[0].size();
	    vector<vector<int>> visited(n,vector<int> (m,0));
	    vector<vector<int>> ans(n,vector<int> (m,0));
	    queue<pair<int , pair<int,int>>> q;
	    for(int i = 0 ; i< n ; i++)
	    {
	        for(int j = 0 ; j < m; j++)
	        {
	            if(grid[i][j] == 1)
	            {
	                q.push({0,{i,j}});
	                visited[i][j] = 1;
	                ans[i][j] = 0;
	            }
	        }
	    }
	    
	    int delRow[] = {0,1,0,-1};
	    int delCol[] = {1,0,-1,0};
	    
	    while(!q.empty())
	    {
	        int dist = q.front().first;
	        int row = q.front().second.first;
	        int col = q.front().second.second;
	        q.pop();
	        
	        for(int i = 0 ; i< 4 ; i++)
	        {
	            int nrow = row + delRow[i];
	            int ncol = col + delCol[i];
	            if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol])
	            {
	                q.push({dist+1,{nrow,ncol}});
	                visited[nrow][ncol] = 1;
	                ans[nrow][ncol] = dist+1;
	            }
	        }
	        
	    }return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends