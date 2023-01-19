//MEMOIZATION APPROACH

#include <bits/stdc++.h>

int solve(int n,vector<vector<int>>& points, int current, int last,vector<vector<int>>& dp){
    if(current == 0){
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i != last){
                maxi = max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    
    if(dp[current][last] != -1){
        return dp[current][last];
    }
    
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i != last){
                    maxi = max(maxi,points[current][i] + solve(n,points,current - 1,i,dp));  
        }
    }
    dp[current][last] = maxi;
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int> (4,-1));
    int current = n-1;
    int last = 3;
    return solve(n,points,n-1,3,dp);
}

//TABULATION APPROACH

#include <bits/stdc++.h>

int solve(int n,vector<vector<int>>& points, int current, int last,vector<vector<int>>& dp){
    if(current == 0){
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i != last){
                maxi = max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    
    if(dp[current][last] != -1){
        return dp[current][last];
    }
    
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i != last){
                    maxi = max(maxi,points[current][i] + solve(n,points,current - 1,i,dp));  
        }
    }
    dp[current][last] = maxi;
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int> (4,0));
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][2],points[0][0]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max({points[0][0],points[0][1],points[0][2]});
    
    for(int i=1;i<n;i++){
        for(int last = 0 ; last<4; last++){
            dp[i][last] = 0;
            for(int task = 0 ; task < 3 ; task++){
                if(task != last){
                    int point = points[i][task] + dp[i-1][task];
                    dp[i][last] = max(dp[i][last],point);
                }
            }
        }
    }
    return dp[n-1][3];
}

//TABULATION WITH SPACE OPTIMISATION
#include <bits/stdc++.h>

int solve(int n,vector<vector<int>>& points, int current, int last,vector<vector<int>>& dp){
    if(current == 0){
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i != last){
                maxi = max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    
    if(dp[current][last] != -1){
        return dp[current][last];
    }
    
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i != last){
                    maxi = max(maxi,points[current][i] + solve(n,points,current - 1,i,dp));  
        }
    }
    dp[current][last] = maxi;
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prevValues(4);
    prevValues[0] = max(points[0][1],points[0][2]);
    prevValues[1] = max(points[0][2],points[0][0]);
    prevValues[2] = max(points[0][0],points[0][1]);
    prevValues[3] = max({points[0][0],points[0][1],points[0][2]});
    
    
    for(int i=1;i<n;i++){
        vector<int> current(4,0);
        for(int last = 0 ; last<4; last++){
            for(int task = 0 ; task < 3 ; task++){
                if(task != last){
                    int point = points[i][task] + prevValues[task];
                    current[last] = max(current[last],point);
                }
            }
        }
        prevValues = current;
    }
    return prevValues[3];
}
