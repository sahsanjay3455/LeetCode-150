class Solution {
public:
 int fun(int ind, int buy, vector<int>& prices, int n, int fee, vector<vector<int>>& dp) {
    if (ind == n) {
        return 0;  // No more days left
    }
    if (dp[ind][buy] != -1) return dp[ind][buy];
    
    int profit = 0;
    if (buy) {
        // Can either buy or skip
        profit = max(-prices[ind] + fun(ind + 1, 0, prices, n, fee, dp), fun(ind + 1, 1, prices, n, fee, dp));
    } else {
        // Can either sell or skip with the transaction fee
        profit = max(prices[ind] - fee + fun(ind + 1, 1, prices, n, fee, dp), fun(ind + 1, 0, prices, n, fee, dp));
    }
    return dp[ind][buy] = profit;
}

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return fun(0, 1, prices, n, fee, dp);
}
};
