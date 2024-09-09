class Solution {
public:
// Helper function to find the longest common subsequence using memoization
    int lcsHelper(string &word1, string &word2, int i, int j, vector<vector<int>> &memo) {
        // Base case: if either string is exhausted
        if (i == word1.size() || j == word2.size()) return 0;

        // If already computed, return the memoized result
        if (memo[i][j] != -1) return memo[i][j];

        // If characters match, include them in the LCS
        if (word1[i] == word2[j]) {
            memo[i][j] = 1 + lcsHelper(word1, word2, i + 1, j + 1, memo);
        } else {
            // If characters don't match, consider the best result by moving one pointer at a time
            memo[i][j] = max(lcsHelper(word1, word2, i + 1, j, memo), lcsHelper(word1, word2, i, j + 1, memo));
        }

        return memo[i][j];
    }
    
    int minDistance(string word1, string word2) 
    {
         int n = word1.size();
        int m = word2.size();

        // Memoization table initialized to -1
        vector<vector<int>> memo(n, vector<int>(m, -1));

        // Find the longest common subsequence
        int lcsLength = lcsHelper(word1, word2, 0, 0, memo);

        // Calculate minimum number of deletions
        return (n - lcsLength) + (m - lcsLength);
        
    }
};