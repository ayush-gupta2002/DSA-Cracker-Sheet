#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<pair<int,int> > > adj;
    int n;

    void addEdge(int u,int v,int weight){
        pair<int,int> p = make_pair(v,weight);
        adj[u].push_back(p);
    }

    void printAdj(){
        for(auto i:adj){
            cout<<i.first<<" ";
            for(auto j:i.second){
                cout<<"("<<j.first<<j.second<<"), ";
            }cout<<endl;
        }
    } 
};

void topologicalSort(stack<int>& s,unordered_map<int,bool>& visited,Graph g,int i){
    visited[i] = true;

    for(pair<int,int>  k: g.adj[i]){
        if(!visited[k.first]){
            topologicalSort(s,visited,g,k.first);
        }
    }
    s.push(i);
}

void shortestPath(Graph g,int src){
    vector<int> res(g.n);
    stack<int> s;
    unordered_map<int,bool> visited;

    for(int i=0;i<g.n;i++){
        if(!visited[i]){
            topologicalSort(s,visited,g,i);
        }
    }
    cout<<"TOPOLOGICAL SORT"<<" ";
    stack<int> s_second = s;
    while(!s_second.empty()){
        cout<<s_second.top()<<" ";
        s_second.pop();
    }cout<<endl;

    for(int i=0;i<g.n;i++){
        res[i] = INT_MAX;
    }
    res[src] = 0;

    while(!s.empty()){
        int frontNode = s.top();
        s.pop();
        if(res[frontNode] != INT_MAX){
            for(pair<int,int> k:g.adj[frontNode]){
                int currentDistance = res[frontNode] + k.second;
                if(currentDistance < res[k.first]){
                    res[k.first] = currentDistance;
                }
            }
        } 
    }
    cout<<"ANSWER IS ";
    for(auto i:res){
        cout<<i<<" ";
    }cout<<endl;
}


int main(){
    Graph g;
    g.n = 6;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printAdj();

    
    shortestPath(g,1);


    return 0;
}
