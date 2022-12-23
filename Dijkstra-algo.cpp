#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int> > > adjList;
    for(int i=0;i<edges;i++){
        pair<int,int> p = make_pair(vec[i][1],vec[i][2]);
        adjList[vec[i][0]].push_back(p);
        p = make_pair(vec[i][0],vec[i][2]);
        adjList[vec[i][1]].push_back(p);
    }
//     for(auto i:adjList){
//         cout << i.first << " -> ";
//         for(auto j:i.second){
//             cout<<"("<<j.first<<","<<j.second<<"), "; 
//         }cout<<endl;
//     }
    
    vector<int> res(vertices);
    for(int i=0;i<vertices;i++){
        res[i] = INT_MAX;
    }
    res[source] = 0;
    
    set<pair<int,int>> s;
    pair<int,int> p = make_pair(0,source);
    s.insert(p);
    
    while(!s.empty()){
        auto p = *(s.begin());
        s.erase(s.begin());
        int nodeDistance = p.first;
        int topNode = p.second;
        for(pair<int,int> k:adjList[topNode]){
            int currentDistance = k.second + nodeDistance;
            if(res[k.first] > currentDistance){
                auto foundRecord = s.find(make_pair(res[k.first],k.first));
                if(foundRecord != s.end()){
                    s.erase(foundRecord);
                }
                res[k.first] = currentDistance;
                pair<int,int> toInsert = make_pair(currentDistance,k.first);
            s.insert(toInsert);
            }
         
        }
    }
    return res;
    
}

