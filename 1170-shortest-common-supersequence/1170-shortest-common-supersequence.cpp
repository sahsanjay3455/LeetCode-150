class Solution {
public:
       // Helper function to find the longest common subsequence using memoization
    int lcsHelper(string &str1, string &str2, int i, int j, vector<vector<int>> &memo) {
        // Base case: if either string is exhausted
        if (i == str1.size() || j == str2.size()) return 0;

        // If already computed, return the memoized result
        if (memo[i][j] != -1) return memo[i][j];

        // If characters match, they are part of the LCS
        if (str1[i] == str2[j]) {
            memo[i][j] = 1 + lcsHelper(str1, str2, i + 1, j + 1, memo);
        } else {
            // If characters don't match, consider the best result by moving one pointer at a time
            memo[i][j] = max(lcsHelper(str1, str2, i + 1, j, memo), lcsHelper(str1, str2, i, j + 1, memo));
        }

        return memo[i][j];
    }

    // Function to construct the shortest common supersequence
    string buildSCS(string &str1, string &str2, int i, int j, vector<vector<int>> &memo) {
        string result = "";

        // Traverse both strings based on the LCS
        while (i < str1.size() && j < str2.size()) {
            if (str1[i] == str2[j]) {
                // If characters match, add them to the result
                result += str1[i];
                i++;
                j++;
            } else if (memo[i + 1][j] >= memo[i][j + 1]) {
                // If moving in str1 gives a better result, add str1[i]
                result += str1[i];
                i++;
            } else {
                // Otherwise, add str2[j]
                result += str2[j];
                j++;
            }
        }

        // Add remaining characters from str1 or str2
        while (i < str1.size()) result += str1[i++];
        while (j < str2.size()) result += str2[j++];

        return result;
    }

    // Main function to find the shortest common supersequence
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        // Memoization table initialized to -1
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));

        // Calculate the longest common subsequence
        lcsHelper(str1, str2, 0, 0, memo);

        // Build the shortest common supersequence using the LCS
        return buildSCS(str1, str2, 0, 0, memo);
    }
};