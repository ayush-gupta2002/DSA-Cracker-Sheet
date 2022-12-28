//DFS APPROACH

class Solution {
public:
    bool dfs(int i,vector<vector<int>>& graph,vector<int>& color,int currentColor){
        color[i] = currentColor;

        for(int k:graph[i]){
            if(color[k] == -1){
                int newColor = !currentColor;
                bool res = dfs(k,graph,color,newColor);
                if(!res){
                    return false;
                }
            }
            else if(color[k] == currentColor){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i] == -1){
                bool res = dfs(i,graph,color,1);
                if(!res){
                    return false;
                }
            }
        }
        return true;
    }
};

//BFS APPROACH 

class Solution {
public:

    void bfs(vector<vector<int>>& graph,int i,vector<int>& color){
        queue<pair<int,int>> q;
        q.push({i,1});

        while(!q.empty()){
            pair<int,int> frontNode = q.front();
            q.pop();
            int currentColor = frontNode.second;
            int topNode = frontNode.first;
            color[topNode] = currentColor; 

            for(int k:graph[topNode]){
                if(color[k] == 0){
                    if(currentColor == 1){
                        q.push({k,2});
                    }
                    else{
                        q.push({k,1});
                    }
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);

        for(int i=0;i<n;i++){
            if(color[i] == 0){
                bfs(graph,i,color);
            }
        }

        for(int i=0;i<n;i++){
            int superColor = color[i];
            for(int k:graph[i]){
                if(color[k] == superColor){
                    return false;
                }
            }
        }
        return true;
    }
};
