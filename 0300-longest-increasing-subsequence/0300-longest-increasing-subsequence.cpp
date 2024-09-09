class Solution {
public:
int lisUtil(vector<int>& nums, int prevIndex, int currIndex, vector<vector<int>>& dp) {
    // Base case: If we have reached the end of the array
    if (currIndex == nums.size()) {
        return 0;
    }
    
    // Check if already computed
    if (dp[prevIndex + 1][currIndex] != -1) {
        return dp[prevIndex + 1][currIndex];
    }

    // Case 1: Do not include the current element
    int notTake = lisUtil(nums, prevIndex, currIndex + 1, dp);

    // Case 2: Include the current element if it is greater than the previous element
    int take = 0;
    if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
        take = 1 + lisUtil(nums, currIndex, currIndex + 1, dp);
    }

    // Store and return the maximum of both cases
    return dp[prevIndex + 1][currIndex] = max(take, notTake);
}

    int lengthOfLIS(vector<int>& nums) 
    {
          int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n, -1));
    return lisUtil(nums, -1, 0, dp);
        
    }
};