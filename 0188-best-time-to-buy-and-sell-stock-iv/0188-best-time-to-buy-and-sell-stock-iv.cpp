class Solution {
public:
    int fun(int ind, int trans, vector<int>& prices, int n, vector<vector<int>>& dp, int k) {
        int profit = 0;
        // Base case: if all transactions are done or end of the array is reached
        if (trans == 2 * k || ind == n) return 0;

        // Check if result is already computed
        if (dp[ind][trans] != -1) return dp[ind][trans];

        // Buying case
        if (trans % 2 == 0) {
            profit = max(-prices[ind] + fun(ind + 1, trans + 1, prices, n, dp, k),
                         0 + fun(ind + 1, trans, prices, n, dp, k));
        }
        // Selling case
        else {
            profit = max(prices[ind] + fun(ind + 1, trans + 1, prices, n, dp, k),
                         0 + fun(ind + 1, trans, prices, n, dp, k));
        }

        // Store the result in dp array
        return dp[ind][trans] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k , -1));  // Correct dp size
        return fun(0, 0, prices, n, dp, k);
    }
};
