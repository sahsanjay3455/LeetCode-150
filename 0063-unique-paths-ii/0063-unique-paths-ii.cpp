class Solution {
public:
    

int uniquePathsWithObstaclesHelper(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& memo) {
    // If the current cell is an obstacle, return 0 as no paths go through here
    if (obstacleGrid[m][n] == 1) return 0;

    // Base case: If we're at the start cell (0,0), there's exactly one path to it
    if (m == 0 && n == 0) return 1;

    // If this subproblem has already been solved, return the cached result
    if (memo[m][n] != -1) return memo[m][n];

    int pathsFromAbove = 0, pathsFromLeft = 0;

    // If we're not in the first row, try to move down from the above cell
    if (m > 0) pathsFromAbove = uniquePathsWithObstaclesHelper(m - 1, n, obstacleGrid, memo);

    // If we're not in the first column, try to move right from the left cell
    if (n > 0) pathsFromLeft = uniquePathsWithObstaclesHelper(m, n - 1, obstacleGrid, memo);

    // Store the total paths to the current cell
    memo[m][n] = pathsFromAbove + pathsFromLeft;

    return memo[m][n];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    // Create a memoization table initialized to -1
    vector<vector<int>> memo(m, vector<int>(n, -1));

    // Call the helper function starting from the bottom-right corner
    return uniquePathsWithObstaclesHelper(m - 1, n - 1, obstacleGrid, memo);
}
};