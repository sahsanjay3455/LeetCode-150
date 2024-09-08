class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<int>& coins, int n, int amount) {
        if (amount == 0) return 0;  // Base case: exact amount is formed.
        if (n == 0 || amount < 0) return INT_MAX;  // No coins left or amount is negative.

        if (dp[n][amount] != -1) return dp[n][amount];  // Use memoized result if available.

        int notTake = solve(dp, coins, n - 1, amount);  // Do not take the current coin.
        int take = INT_MAX;
        if (amount >= coins[n - 1]) {  // Try taking the current coin if it's <= amount.
            int result = solve(dp, coins, n, amount - coins[n - 1]);
            if (result != INT_MAX) {
                take = 1 + result;
            }
        }

        return dp[n][amount] = min(take, notTake);  // Memoize and return the minimum result.
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if (amount == 0) return 0;  // No amount means no coins are needed.
        
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));  // Initialize memoization table.

        int result = solve(dp, coins, n, amount);
        return result == INT_MAX ? -1 : result;  // Return -1 if no solution, otherwise the result.
    }
};
