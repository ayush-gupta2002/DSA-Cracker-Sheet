class Solution {
public:

    void dfs(int i, vector<int>& visited, set<pair<int,int>>& s, unordered_map<int,list<int>>& adjList,int& res){
        visited[i] = 1;

        for(int k:adjList[i]){
            if(!visited[k]){
                if(s.find({i,k}) != s.end()){
                    res++;
                }
                dfs(k,visited,s,adjList,res);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int>> adjList;
        set<pair<int,int>> s;

        for(vector<int> edge:connections){
            int u = edge[0];
            int v = edge[1];
            s.insert({u,v});
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int> visited(n,0);
        int res = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,s,adjList,res);
            }
        }

        return res;

    }
};
