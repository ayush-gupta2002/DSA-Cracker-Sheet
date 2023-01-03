class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,list<pair<int,int>>> adjList;
        for(vector<int> flight:flights){
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];

            adjList[u].push_back({v,price});
        }

        queue<vector<int>> q;
        //q structure --> stops, node, price
        q.push({0,src,0});
        vector<int> price(n,INT_MAX);
        price[src] = 0;

        while(!q.empty()){
            vector<int> frontVec = q.front();
            q.pop();
            int stops = frontVec[0];
            int node = frontVec[1];
            int oldPrice = frontVec[2];

            for(pair<int,int> it:adjList[node]){
                int currentPrice = oldPrice + it.second;
                if(currentPrice < price[it.first] && stops<=k){
                    price[it.first] = currentPrice;
                    q.push({stops+1,it.first,currentPrice});
                }
            }
        }
        if(price[dst] == INT_MAX){
            return -1;
        }
        return price[dst];
    }
};
