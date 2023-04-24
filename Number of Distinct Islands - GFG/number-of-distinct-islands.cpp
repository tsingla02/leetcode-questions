//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void dfs(vector<vector<int>>& t, int a , int b, int n, int m , int row, int col, vector<vector<int>>& visited , vector<vector<int>>& grid)
    {
        vector<int> tab;
        tab.push_back(row-a);
        tab.push_back(col-b);
        t.push_back(tab);
        visited[row][col] = 1;
        int delRow[] = {1,0,-1,0};
        int delCol[] = {0,1,0,-1};
        for(int i = 0 ; i < 4 ; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                dfs(t,a,b,n,m,nrow,ncol,visited,grid);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        set<vector<vector<int>>> st;
        for(int i = 0 ; i< n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(!visited[i][j] && grid[i][j] == 1)
                {
                    vector<vector<int>> t;
                    int a = i;
                    int b = j;
                    dfs(t,a,b,n,m,i,j,visited,grid);
                    st.insert(t);
                    t.clear();
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends