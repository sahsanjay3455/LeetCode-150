class Solution {
public:
 // Helper function using memoization
    int longestPalindromeSubseqHelper(string &s, int i, int j, vector<vector<int>> &memo) {
        // Base case: if i exceeds j, no subsequence is possible
        if (i > j) return 0;

        // Base case: if i equals j, a single character is a palindrome of length 1
        if (i == j) return 1;

        // If the result is already computed, return it
        if (memo[i][j] != -1) return memo[i][j];

        // If characters match, include them in the palindromic subsequence
        if (s[i] == s[j]) {
            memo[i][j] = 2 + longestPalindromeSubseqHelper(s, i + 1, j - 1, memo);
        } else {
            // If characters don't match, take the maximum by ignoring one of the characters
            memo[i][j] = max(longestPalindromeSubseqHelper(s, i + 1, j, memo), 
                             longestPalindromeSubseqHelper(s, i, j - 1, memo));
        }

        return memo[i][j];
    }
    int longestPalindromeSubseq(string s) 
    {
           int n = s.size();
        // Memoization table initialized to -1
        vector<vector<int>> memo(n, vector<int>(n, -1));

        // Start recursion from the entire string (0, n-1)
        return longestPalindromeSubseqHelper(s, 0, n - 1, memo);
        
    }
};