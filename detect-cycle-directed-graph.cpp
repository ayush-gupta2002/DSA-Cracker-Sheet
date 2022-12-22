//USING DFS ALGO

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

//USING BFS ALGO
#include <bits/stdc++.h>

bool bfs(int i,unordered_map<int,bool>& visited,unordered_map<int,list<int>>& adjList,vector<int>& indegree,int& count){
    queue<int> q;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i] == 0){
            q.push(i);
            visited[i] = true;
        }
    }
    
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        count++;
        visited[frontNode] = true;
        for(int k:adjList[frontNode]){
            indegree[k]--;
            if(indegree[k] == 0){
                q.push(k);
            }
        }
        
    }
}


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int,list<int>> adjList;
    for(pair<int,int> edge:edges){
        int u = edge.first - 1;
        int v = edge.second - 1;
        
        adjList[u].push_back(v);
    }
    unordered_map<int,bool> visited;
    int count = 0;
    
    vector<int> indegree(n);
    for(auto i:adjList){
        for(auto k:i.second){
            indegree[k]++;
        }
    }
    
    for(int i=1;i<n;i++){
        if(!visited[i]){
            bool res = bfs(i,visited,adjList,indegree,count);
        }
    }
    if(count == n){
        return false;
    }
    return true;
    
}
