class Solution {
public:
     // Helper function with memoization
    int numDistinctHelper(string &s, string &t, int i, int j, vector<vector<int>> &memo) {
        // If t is fully matched, we've found a valid subsequence
        if (j == t.size()) return 1;
        // If s is exhausted but t is not, we can't form the subsequence
        if (i == s.size()) return 0;
        
        // Check if the result is already computed
        if (memo[i][j] != -1) return memo[i][j];
        
        // Option 1: Skip the current character of s
        int result = numDistinctHelper(s, t, i + 1, j, memo);
        
        // Option 2: Use the current character if it matches t[j]
        if (s[i] == t[j]) {
            result += numDistinctHelper(s, t, i + 1, j + 1, memo);
        }

        // Memoize the result
        memo[i][j] = result;
        return result;
    }
    
    // Main function to calculate the number of distinct subsequences
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        // Memoization table initialized to -1
        vector<vector<int>> memo(n, vector<int>(m, -1));
        
        // Start from the beginning of both strings
        return numDistinctHelper(s, t, 0, 0, memo);
    }
};