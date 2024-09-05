class Solution {
public:
    // Function to calculate unique paths with memoization
    int uniquePathsHelper(int i, int j, vector<vector<int>>& dp) 
    {
        // Base case: if we reach the top-left corner, there's only one way (starting point)
        if (i == 0 && j == 0) return 1;
        // If we go out of bounds, no paths are possible
        if (i < 0 || j < 0) return 0;
        
        // Check if the value has already been computed
        if (dp[i][j] != -1) return dp[i][j];
        
        // Recursive relation: paths from above + paths from the left
        
        int fromAbove = uniquePathsHelper(i - 1, j, dp);
        int fromLeft = uniquePathsHelper(i, j - 1, dp);
        
        // Store the result in dp table and return it
        return dp[i][j] = fromAbove + fromLeft;
    }


    int uniquePaths(int m, int n) {
        // Memoization table initialized with -1
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // Start from the bottom-right corner
        return uniquePathsHelper(m - 1, n - 1, dp);
    }
};
