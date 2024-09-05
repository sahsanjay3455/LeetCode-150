class Solution {
public:
   int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Initialize the last row of dp table with the values of the last row of triangle
        for (int j = 0; j < n; ++j) {
            dp[n-1][j] = triangle[n-1][j];
        }
        
        // Fill the dp table from bottom to top
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        
        // The result is at the top of the triangle
        return dp[0][0];
    }
};