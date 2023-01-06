class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,list<pair<int,int>>> adjList;

        for(vector<int> edge:times){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adjList[u].push_back({v,w});
        }

        set<pair<int,int>> s;
        vector<int> distance(n+1,INT_MAX);
        distance[k] = 0;
        s.insert({0,k});
        int res = INT_MIN;
        vector<int> visited(n+1,0);

        while(!s.empty()){
            auto p = *(s.begin());
            s.erase(s.begin());

            int currentNode = p.second;
            int currentTime = p.first;
            visited[currentNode] = 1;

            for(pair<int,int> k:adjList[currentNode]){
                visited[k.first] =1;
                int newTime = currentTime + k.second;
                if(newTime < distance[k.first]){
                    distance[k.first] = newTime;
                    s.insert({newTime, k.first});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(visited[i]==0){
                return -1;
            }
        }
        for(int i:distance){
            if(i!=INT_MAX){
                res = max(i,res);
            }
        }
        if(res == 0){
            return -1;
        }
        return res;

    }
};
