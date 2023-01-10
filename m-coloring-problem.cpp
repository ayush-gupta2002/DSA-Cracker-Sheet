//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool isValid(int clr,int i, unordered_map<int,list<int>>& adjList, vector<int>& res){
        for(int k:adjList[i]){
            if(clr == res[k]){
                return false;
            }
        }
        return true;
    }
    
    bool dfs(vector<int>& visited, int i, unordered_map<int,list<int>>& adjList, vector<int>& res, int m){
        if(i>=res.size()){
            return true;
        }
        visited[i] = 1;
        for(int clr=1;clr<=m;clr++){
            if(isValid(clr,i,adjList,res)){
                res[i] = clr;
                bool ans = dfs(visited,i+1,adjList,res,m);
                if(ans){
                    return true;
                }
                res[i] = 0;
            }
        }
        return false;
        
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        unordered_map<int,list<int>> adjList;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        vector<int> res(n,0);
        vector<int> visited(n,0);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bool ans = dfs(visited,i,adjList,res,m);
                if(!ans){
                    return false;
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<visited[i]<<" ";
        // }cout<<endl;
        
        // for(int i=0;i<n;i++){
        //     cout<<res[i]<<" ";
        //     if(res[i] == 0){
        //         return false;
        //     }
        // }cout<<endl;
        return true;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
