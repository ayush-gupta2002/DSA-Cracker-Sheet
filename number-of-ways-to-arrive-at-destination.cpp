class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<long long int,list<pair<long long int,long long int>>> adjList;
        for(vector<int> road:roads){
            long long int u = road[0];
            long long int v = road[1];
            long long int time = road[2];

            adjList[u].push_back({v,time});
            adjList[v].push_back({u,time});
        }

        // s structure --> time, intersection
        set<pair<long long int,long long int>> s;
        s.insert({0,0});
        vector<long long int> time(n, 1e18);
        time[0] = 0;
        vector<long long int> ways(n, 0);
        ways[0] = 1;
        int mod = (int)(1e9 + 7);

        while(!s.empty()){
            auto p = *(s.begin());
            s.erase(s.begin());
            long long int intersection = p.second;
            long long int oldTime = p.first;


            for(pair<long long int,long long int> it:adjList[intersection]){
                long long int adjNode = it.first;
                long long int adjTime = it.second;

                if(oldTime + adjTime < time[adjNode]){
                    ways[adjNode] = ways[intersection];
                    time[adjNode] = oldTime + adjTime;
                    s.insert({oldTime + adjTime,adjNode});
                }
                else if(oldTime + adjTime == time[adjNode]){
                   ways[adjNode] = (ways[adjNode] + ways[intersection]) % mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};
