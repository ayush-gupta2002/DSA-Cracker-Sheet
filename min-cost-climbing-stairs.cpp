class Solution {
public:

    int climbUtil(int current,int n,vector<int>& cost,vector<int>& minCost){
        if(current >= n-2){
            minCost[current] = cost[current];
        }
        else if(minCost[current] == -1){
            minCost[current] = cost[current] + min(climbUtil(current+1,n,cost,minCost), climbUtil(current+2,n,cost,minCost));
        }
        return minCost[current];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> minCost(n,-1);
        return min(climbUtil(0,n,cost,minCost), climbUtil(1,n,cost,minCost));


    }
};
