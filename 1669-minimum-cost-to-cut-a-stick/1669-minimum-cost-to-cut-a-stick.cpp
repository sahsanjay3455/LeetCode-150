class Solution {
public:
    // DP table for memoization
    vector<vector<int>> dp;
    vector<int> cuts;

    // Helper function to find the minimum cost between left and right cuts
    int findMinCost(int left, int right) {
        // Base case: No more cuts between left and right
        if (left + 1 == right) return 0;
        
        // If already computed, return the result from dp
        if (dp[left][right] != -1) return dp[left][right];
        
        int cost = INT_MAX;
        
        // Try making each cut between left and right and calculate the cost
        for (int i = left + 1; i < right; ++i) {
            int currentCost = cuts[right] - cuts[left] + findMinCost(left, i) + findMinCost(i, right);
            cost = min(cost, currentCost);
        }
        
        // Memoize the result
        return dp[left][right] = cost;
    }

    int minCost(int n, vector<int>& cuts) {
        // Add the two ends of the stick (0 and n) to the cuts array
        cuts.push_back(0);
        cuts.push_back(n);
        
        // Sort the cuts to process them in order
        sort(cuts.begin(), cuts.end());
        
        // Initialize memoization table with -1
        int m = cuts.size();
        dp = vector<vector<int>>(m, vector<int>(m, -1));
        
        // Store the cuts in the class for access in the helper function
        this->cuts = cuts;
        
        // Call the helper function for the entire stick (from 0 to m-1)
        return findMinCost(0, m - 1);
    }
};

