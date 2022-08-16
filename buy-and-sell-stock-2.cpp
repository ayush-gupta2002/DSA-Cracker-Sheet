class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int current_min=prices[0];
        
        int n = prices.size();
        for(int i=0;i<n;i++){
            current_min = min(current_min,prices[i]);
            int current_profit = prices[i] - current_min;
            max_profit = max(current_profit,max_profit);
        }
        return max_profit;
        
    }
};
