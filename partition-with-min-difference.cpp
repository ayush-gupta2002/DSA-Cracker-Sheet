class Solution {
public:


    int minimumDifference(vector<int>& arr) {
        int totalSum = 0;
        int n = arr.size();
        for(int it:arr){
            totalSum += it;
        }

        vector<vector<int>> dp(n, vector<int> (abs(totalSum) + 1, 0));
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        if(arr[0]<=totalSum){
            dp[0][arr[0]] = true;
        }

        for(int i=1;i<n;i++){
            for(int target = 1;target<=totalSum;target++){
                bool left = false;
                if(target>=arr[i]){
                    left = dp[i-1][target-arr[i]];
                }
                bool right = dp[i-1][target];
                dp[i][target] = left || right;
            }
        }  
        int mini = 1e9; 

        for(int s1 = 0 ;s1 <= totalSum/2 ; s1++){
            if(dp[n-1][s1] == 1){
                cout<<s1<<" ";
                // mini = min(mini, abs(totalSum - (2*s1)));
                cout<<totalSum - (2*s1)<<endl;
            }
        }
        return mini;
    }
};
