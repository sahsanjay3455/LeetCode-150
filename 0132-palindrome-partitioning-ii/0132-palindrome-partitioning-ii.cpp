class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        // Step 1: Precompute whether each substring is a palindrome
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        // Initialize the palindrome table
        for (int i = 0; i < n; i++) {
            isPalindrome[i][i] = true; // Single character is always a palindrome
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len == 2 || isPalindrome[i + 1][j - 1]) {
                        isPalindrome[i][j] = true;
                    }
                }
            }
        }

        // Step 2: Compute the minimum cuts using DP
        vector<int> dp(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (isPalindrome[0][i]) {
                dp[i] = 0; // No cut needed if s[0...i] is a palindrome
            } else {
                dp[i] = i; // Max cuts is i (cutting every character individually)
                for (int j = 1; j <= i; j++) {
                    if (isPalindrome[j][i]) {
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};
