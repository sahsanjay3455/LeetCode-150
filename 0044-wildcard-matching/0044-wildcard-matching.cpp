class Solution {
public:
// Function to perform wildcard matching
bool isMatchUtil(const string& s, const string& p, int i, int j, vector<vector<int>>& memo) {
    // Base case: if both string and pattern are exhausted
    if (i < 0 && j < 0) return true;

    // If pattern is exhausted but string is not
    if (j < 0) return false;

    // If string is exhausted but pattern is not
    if (i < 0) {
        // Check if remaining pattern is all '*'
        while (j >= 0 && p[j] == '*') j--;
        return j < 0;
    }

    // Check memoization table
    if (memo[i][j] != -1) return memo[i][j];

    // If characters match or pattern has '?'
    if (s[i] == p[j] || p[j] == '?') {
        return memo[i][j] = isMatchUtil(s, p, i - 1, j - 1, memo);
    }

    // If pattern has '*', we have two choices:
    // 1. Treat '*' as matching no characters (move to next character in pattern)
    // 2. Treat '*' as matching one or more characters (move to next character in string)
    if (p[j] == '*') {
        return memo[i][j] = isMatchUtil(s, p, i - 1, j, memo) || isMatchUtil(s, p, i, j - 1, memo);
    }

    // If characters do not match
    return memo[i][j] = false;
}

// Main function to check if string matches pattern
bool isMatch(const string& s, const string& p) {
    int n = s.size();
    int m = p.size();
    // Create a memoization table initialized to -1
    vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
    return isMatchUtil(s, p, n - 1, m - 1, memo);
}
};