#include <bits/stdc++.h>

bool dfs(int i,unordered_map<int,bool>& visited, unordered_map<int,bool>& dfsVisited,unordered_map<int,list<int>>& adjList){
    visited[i] = true;
    dfsVisited[i] = true;
    
    for(int k:adjList[i]){
        if(!visited[k]){
            bool res = dfs(k,visited,dfsVisited,adjList);
            if(res){
                return true;
            }
        }
        if(visited[k] && dfsVisited[k]){
            return true;
        }
    }
    dfsVisited[i] = false;
    return false;
}


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int,list<int>> adjList;
    for(pair<int,int> edge:edges){
        int u = edge.first;
        int v = edge.second;
        
        adjList[u].push_back(v);
    }
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;
    
    for(int i=1;i<n;i++){
        if(!visited[i]){
            bool res = dfs(i,visited,dfsVisited,adjList);
            if(res){
                return 1;
            }
        }
    }
    return 0;
    
}
