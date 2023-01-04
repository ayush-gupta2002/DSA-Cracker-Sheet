class Solution {
public:

    vector<int> djikstra(unordered_map<int,list<pair<int,int>>>& adjList,int n, int src){
        vector<int> distance(n,INT_MAX);
        distance[src] = 0;

        set<pair<int,int>> s;
        //s --> distance, node
        s.insert({0,src});

        while(!s.empty()){
            auto p = *(s.begin());
            s.erase(s.begin());
            int oldDistance = p.first;
            int city = p.second;

            for(pair<int,int> it:adjList[city]){
                int currentDistance = it.second + oldDistance;
                if(currentDistance < distance[it.first]){
                    distance[it.first] = currentDistance;
                    s.insert({currentDistance,it.first});
                }
            }
        }
        return distance;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,list<pair<int,int>>> adjList;

        for(vector<int> edge:edges){
            int u = edge[0];
            int v = edge[1];
            int d = edge[2];
            adjList[u].push_back({v,d});
            adjList[v].push_back({u,d});
        }
        int smallest = INT_MAX;
        int smallestIndex = -1;
        for(int i=0;i<n;i++){
            vector<int> distance = djikstra(adjList,n,i);
            int count = 0;
            for(int j=0;j<distance.size();j++){
                if(distance[j] <= distanceThreshold){
                    count++;
                }
            }
            if(count <= smallest){
                smallest = count;
                smallestIndex = i;
            }
        }
        return smallestIndex;
    }
};
