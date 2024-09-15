class Solution {
public:
unordered_map<string, bool> memo; // Memoization cache

    bool dp(int i, int j, const string &s, const string &p) {
        // Create a unique key for memoization
        string key = to_string(i) + "," + to_string(j);
        
        // Check if the result is already in the memo
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        // Base case: if we reach the end of the pattern
        if (j == p.size()) {
            return i == s.size();
        }

        // Check if the first characters match
        bool first_match = (i < s.size() && (p[j] == s[i] || p[j] == '?'));

        // If the current character in the pattern is '*'
        if (p[j] == '*') {
            // '*' can match an empty sequence or one/more characters
            memo[key] = dp(i, j + 1, s, p) || (i < s.size() && dp(i + 1, j, s, p));
        } else {
            // Otherwise, proceed with regular matching
            memo[key] = first_match && dp(i + 1, j + 1, s, p);
        }

        return memo[key];
    }

    bool isMatch(string s, string p) {
        return dp(0, 0, s, p);
    }
};