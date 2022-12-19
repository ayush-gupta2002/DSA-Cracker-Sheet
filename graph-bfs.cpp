#include <bits/stdc++.h> 

void prepareAdjList(unordered_map<int,set<int>>& adj,vector<pair<int,int>>& edges){
    for(pair<int,int> edge:edges){
        int u = edge.first;
        int v = edge.second;
        adj[u].insert(v);
        adj[v].insert(u);
    }
}

void bfs(unordered_map<int,set<int>>& adj,unordered_map<int,bool>& visited, vector<int>& res, int i){
    queue<int> q;
    q.push(i);
    visited[i] = true;
    
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        res.push_back(frontNode);
        for(auto i:adj[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,set<int>> adj;
    vector<int> res;
    unordered_map<int,bool>visited;
    
    prepareAdjList(adj,edges);
    
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adj,visited,res,i);
        }
    }
    return res;
}
