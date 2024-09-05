class Solution {
public:
  // Recursive function to find minimum path sum with memoization
    int findMinPath(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        // Base case: if we are at the bottom row, return the value at this cell
        if (i == triangle.size() - 1) return triangle[i][j];
        
        // Check if the result is already computed
        if (dp[i][j] != -1) return dp[i][j];
        
        // Recursively compute the minimum path sum for the current cell
        int down = findMinPath(i + 1, j, triangle, dp); // move to the cell directly below
        int diagonal = findMinPath(i + 1, j + 1, triangle, dp); // move to the cell diagonally below
        
        // Store the result in dp table and return it
        return dp[i][j] = triangle[i][j] + min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // Initialize the memoization table with -1
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // Start the recursion from the top of the triangle
        return findMinPath(0, 0, triangle, dp);
    
    }
};