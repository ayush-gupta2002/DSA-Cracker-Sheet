//USING BFS ALGO


#include <bits/stdc++.h>

bool bfs(unordered_map<int,list<int>>& adjList,int i,unordered_map<int,bool>& visited){
        queue<int> q;
        unordered_map<int,int> parent;
        q.push(i);
        visited[i] = true;
        parent[i] = -1;
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            for(int k:adjList[frontNode]){
                if(visited[k] && parent[frontNode] != k){
                    return true;
                }
                else if(!visited[k] && k!=parent[frontNode]){
                    visited[k] = true;
                    q.push(k);
                    parent[k] = frontNode;
                }
            }
        }
        return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int> > adjList;
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    unordered_map<int,bool> visited;
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool res = bfs(adjList,i,visited);
            if(res){
                return "Yes";
            }
        }
    }
    return "No";
}


//USING DFS ALGO


#include <bits/stdc++.h>

bool dfs(unordered_map<int,list<int> >&adjList,int i,unordered_map<int,bool>& visited,int parent){
    visited[i] = true;
    
    for(int k:adjList[i]){
        if(!visited[k]){
            bool cycleDetected = dfs(adjList,k,visited,i);
            if(cycleDetected){
                return true;
            }
        }
        else if(parent != k){
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int> > adjList;
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    unordered_map<int,bool> visited;
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool res = dfs(adjList,i,visited,-1);
            if(res){
                return "Yes";
            }
        }
    }
    return "No";
}

