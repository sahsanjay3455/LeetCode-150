class Solution {
public:
int fun(int ind, int buy, vector<int>& prices, int n, vector<vector<int>>& dp) {
    if (ind >= n) {
        return 0;  // No more days left
    }
    if (dp[ind][buy] != -1) return dp[ind][buy];
    
    int profit = 0;
    if (buy) {
        // Can either buy or skip
        profit = max(-prices[ind] + fun(ind + 1, 0, prices, n, dp), fun(ind + 1, 1, prices, n, dp));
    } else {
        // Can either sell or skip with cooldown (move to day + 2 after selling)
        profit = max(prices[ind] + fun(ind + 2, 1, prices, n, dp), fun(ind + 1, 0, prices, n, dp));
    }
    return dp[ind][buy] = profit;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return fun(0, 1, prices, n, dp);
        
    }
};