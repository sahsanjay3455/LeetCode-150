class Solution {
public:
    vector<vector<int>> dp; // Memoization table

    // Helper function to calculate the maximum coins between left and right
    int maxCoinsHelper(vector<int>& nums, int left, int right) {
        // Base case: no balloons between left and right
        if (left + 1 == right) return 0;
        
        // If already computed, return the stored result
        if (dp[left][right] != -1) return dp[left][right];
        
        int maxCoins = 0;

        // Try bursting each balloon between left and right as the last one
        for (int i = left + 1; i < right; ++i) {
            int currentCoins = nums[left] * nums[i] * nums[right]; // Coins from bursting i
            currentCoins += maxCoinsHelper(nums, left, i) + maxCoinsHelper(nums, i, right); // Recursively solve for subarrays
            maxCoins = max(maxCoins, currentCoins); // Track the maximum coins
        }
        
        // Memoize the result
        return dp[left][right] = maxCoins;
    }

    int maxCoins(vector<int>& nums) {
        // Add virtual balloons with value 1 at both ends
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        int n = nums.size();
        // Initialize dp table with -1 (uncomputed)
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        
        // Calculate the maximum coins for the entire array (from 0 to n-1, excluding boundaries)
        return maxCoinsHelper(nums, 0, n - 1);
    }
};
