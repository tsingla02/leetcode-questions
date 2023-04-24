//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    int flag = 0;
    // void bfs(int node, vector<int>& visited, vector<int>adj[])
    // {
       
    // }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> visited(V,0);
	    for(int i = 0 ; i< V ; i++)
	    {
	        if(!visited[i])
	        {
	            visited[i] = 1;
	            queue<pair<int,int>> q;
                q.push({1,i});
                while(!q.empty())
                {
                    int n = q.front().second;
                    int color = q.front().first;
                    q.pop();
                    for(auto x : adj[n])
                    {
                        if(visited[x] && color == visited[x]) {return 0;}
                        else if(!visited[x] && color == 1)
                        {
                            visited[x] = 2;
                            q.push({2,x});
                        }
                        else if(!visited[x] && color == 2)
                        {
                            visited[x] = 1;
                            q.push({1,x});
                        }
                    }
        }
	        }
	    }
	   // if(flag == 1)return 0;
	    return 1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends