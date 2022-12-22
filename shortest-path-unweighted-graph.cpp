#include <unordered_map>
#include <vector>
#include <list>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
    vector<int> res;
    
    unordered_map<int,list<int>> adjList;
    
    for(auto edge:edges){
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int> q;
    
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        for(int k : adjList[frontNode]){
            if(!visited[k]){
                q.push(k);
                visited[k] = true;
                parent[k] = frontNode;
            }
        }
    }
    int currentHouse = t;
    while(currentHouse != s){
        res.push_back(currentHouse);
        currentHouse = parent[currentHouse];
    }
    res.push_back(currentHouse);
    reverse(res.begin(),res.end());
    return res;
}

