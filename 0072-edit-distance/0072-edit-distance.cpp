class Solution {
public:
   int minDisRec(const string& s1, const string& s2, int m, int n, vector<vector<int>>& memo) {
    // Base cases
    if (m == 0) return n;  // If s1 is empty, insert all characters of s2
    if (n == 0) return m;  // If s2 is empty, remove all characters of s1

    // Check if result is already computed
    if (memo[m][n] != -1) return memo[m][n];

    // If last characters are the same, no operation needed
    if (s1[m - 1] == s2[n - 1]) {
        memo[m][n] = minDisRec(s1, s2, m - 1, n - 1, memo);
    } else {
        // Calculate the minimum of three operations
        int insertOp = minDisRec(s1, s2, m, n - 1, memo);    // Insert
        int deleteOp = minDisRec(s1, s2, m - 1, n, memo);    // Delete
        int replaceOp = minDisRec(s1, s2, m - 1, n - 1, memo);  // Replace
        memo[m][n] = 1 + min({insertOp, deleteOp, replaceOp});
    }

    return memo[m][n];
}

int minDistance(const string& s1, const string& s2) {
    int m = s1.length(), n = s2.length();
    // Initialize memoization table
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
    return minDisRec(s1, s2, m, n, memo);
}
};