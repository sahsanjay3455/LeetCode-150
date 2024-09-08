

class Solution {
public:
    // Recursive function with memoization to find LCS
    int lcsHelper(string &text1, string &text2, int i, int j, vector<vector<int>>& dp) {
        // Base case: if any string is fully traversed, return 0
        if (i == 0 || j == 0) return 0;
        
        // If the result is already computed, return it
        if (dp[i][j] != -1) return dp[i][j];
        
        // If characters match, add 1 to the result and solve for remaining strings
        if (text1[i - 1] == text2[j - 1]) {
            dp[i][j] = 1 + lcsHelper(text1, text2, i - 1, j - 1, dp);
        } else {
            // If characters don't match, find the maximum by skipping one character from either string
            dp[i][j] = max(lcsHelper(text1, text2, i - 1, j, dp), lcsHelper(text1, text2, i, j - 1, dp));
        }
        
        return dp[i][j];
    }

    // Main function to find the length of the longest common subsequence
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        // Create a memoization table initialized with -1
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        // Call the helper function to solve the problem
        return lcsHelper(text1, text2, n, m, dp);
    }
};