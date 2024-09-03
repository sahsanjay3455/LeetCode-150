class Solution {
public:


   int uniquePathsHelper(int m, int n, vector<vector<int>>& memo) {
    // Base case: when either row or column is 1, there's only one path
    if (m == 1 || n == 1) return 1;

    // If the value is already computed, return it
    if (memo[m][n] != -1) return memo[m][n];

    // Compute the number of unique paths by moving either right or down
    memo[m][n] = uniquePathsHelper(m - 1, n, memo) + uniquePathsHelper(m, n - 1, memo);

    return memo[m][n];
}

int uniquePaths(int m, int n) {
    // Create a memoization table initialized to -1
    vector<vector<int>> memo(m+1 , vector<int>(n+1, -1));

    // Call the helper function
    return uniquePathsHelper(m, n, memo);
}
};