
class Solution {
public:
    // Memoized function to check if substring s[start:end+1] is a palindrome
    bool isPalindrome(const string& s, int start, int end, vector<vector<int>>& dp) {
        // Base cases
        if (start >= end) return true;  // Single character or empty substring
        if (dp[start][end] != -1) return dp[start][end];  // Return memoized result

        // Check if characters match and the inner substring is a palindrome
        if (s[start] == s[end] && isPalindrome(s, start + 1, end - 1, dp)) {
            dp[start][end] = true;
            return true;
        } else {
            dp[start][end] = false;
            return false;
        }
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (isPalindrome(s, i, j, dp)) {
                    if (j - i + 1 > maxLength) {
                        start = i;
                        maxLength = j - i + 1;
                    }
                }
            }
        }

        return s.substr(start, maxLength);
    }
};
