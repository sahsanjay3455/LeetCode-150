class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        
        sort(nums.begin(), nums.end()); // Sort to make divisible conditions easier to check
        
        // Memoization arrays
        vector<int> dp(n, 1);  // dp[i] = size of largest divisible subset ending with nums[i]
        vector<int> prev(n, -1); // prev[i] stores the index of previous element in the subset
        
        int maxSize = 1, maxIndex = 0;
        
        // Populate the memoization arrays
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxIndex = i;
            }
        }
        
        // Reconstruct the largest divisible subset
        vector<int> result;
        while (maxIndex != -1) {
            result.push_back(nums[maxIndex]);
            maxIndex = prev[maxIndex];
        }
        
        reverse(result.begin(), result.end());  // Reverse to get the subset in correct order
        return result;
    }
};