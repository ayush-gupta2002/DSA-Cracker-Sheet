//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  
  void dfs(int V,vector<int>adj[],int i,vector<int>& disc,vector<int>&low,vector<int>&visited,int timer,int parent,vector<int>&res){
      visited[i] = 1;
      disc[i] = timer;
      low[i] = timer;
      timer ++;
      int child = 0;
      
      for(int k:adj[i]){
          if(k == parent){
              continue;
          }
          if(visited[k] == 0){
              dfs(V,adj,k,disc,low,visited,timer,i,res);
              low[i] = min(low[i],low[k]);
              
              if(low[k] >= disc[i] && parent != -1){
                  res[i] = 1;
              }
              child++;
          }
          else{
              low[i] = min(low[i],disc[k]);
          }
      }
      if(parent == -1 && child > 1){
                  res[i] = 1;
          
      }
  }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        int timer = 0;
        vector<int> disc(V);
        vector<int> low(V);
        vector<int> visited(V);
        
        for(int i=0;i<V;i++){
            disc[i] = -1;
            low[i] = -1;
            visited[i] = 0;
        }
        vector<int> res(V);
        int parent = -1;
        
        for(int i=0;i<V;i++){
            if(visited[i] == 0){
                dfs(V,adj,i,disc,low,visited,timer,parent,res);
            }
        }
        vector<int> AP;
        for(int i=0;i<V;i++){
            if(res[i] == 1){
                AP.push_back(i);
            }
        }
        if(AP.empty()){
            AP.push_back(-1);
            return AP;
        }
        return AP;
        
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
