//MEMOIZATION

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int solve(int wt[],int val[],int curri,int W,vector<vector<int>>& dp){
        if(W<0){
            return INT_MIN;
        }
        else if(curri == 0){
            if(wt[0] <= W){
                return val[0];
            }
            else{
                return 0;
            }
        }
        if(dp[curri][W] != -1){
            return dp[curri][W];
        }
        
        int left = solve(wt,val,curri-1,W,dp);
        int right = val[curri] + solve(wt,val,curri-1,W-wt[curri],dp);
        
        return dp[curri][W] = max(left,right);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp (n,vector<int>(W+1,-1));
       return solve(wt,val,n-1,W,dp);
    }
};

//TABULATION

    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp (n,vector<int>(W+1,0));

       for(int cwt=wt[0];cwt<=W;cwt++){
           dp[0][cwt] = val[0];
       }    
       
       for(int curri=1;curri<n;curri++){
           for(int cwt=0;cwt<=W;cwt++){
               int left = dp[curri-1][cwt];
               int right = INT_MIN;
               if(cwt >= wt[curri]){
                   right = val[curri] + dp[curri-1][cwt - wt[curri]];
               }
               dp[curri][cwt] = max(left,right);
           }
       }
       return dp[n-1][W];
    }
