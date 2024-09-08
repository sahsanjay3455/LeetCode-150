class Solution {
public:
    int solve(vector<int>& coins, vector<vector<int>>& dp, int n, int amount) {
        // Base cases
        if (amount == 0) return 1;  // If amount is 0, there's 1 way to make the change
        if (amount < 0 || n <= 0) return 0;  // No way to make change if amount is negative or no coins are left
        
        // Check if the subproblem is already solved
        if (dp[n][amount] != -1) return dp[n][amount];

        // Not take the current coin
        int notTake = solve(coins, dp, n - 1, amount);

        // Initialize the take variable before using it
        int take = 0;
        if (amount >= coins[n - 1]) {
            // Take the current coin
            take = solve(coins, dp, n, amount - coins[n - 1]);
        }

        // Store the result in the memo table and return it
        return dp[n][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // Initialize dp array with -1 (for memoization)
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        // Call the recursive solve function
        return solve(coins, dp, n, amount);
    }
};
