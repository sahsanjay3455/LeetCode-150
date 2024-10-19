class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int totalSquares = 0;
        
        // Traverse the matrix and fill the dp table
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // If it's a '1', we calculate the largest square ending at (i, j)
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        // First row or first column can only form squares of size 1
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    }
                    // Accumulate the total number of squares
                    totalSquares += dp[i][j];
                }
            }
        }
        
        return totalSquares;
    }
};