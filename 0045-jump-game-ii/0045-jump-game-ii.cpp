class Solution {
public:
     int jumpHelper(vector<int>& nums, int index, vector<int>& dp) {
        // Base case: If already at or beyond the last index, no more jumps are needed
        if (index >= nums.size() - 1) {
            return 0;
        }
        
        // If result for the current index is already calculated, return it
        if (dp[index] != -1) {
            return dp[index];
        }
        
        int minJumps = INT_MAX;
        int maxJump = nums[index];  // Max jump from the current index
        
        // Try all possible jumps from the current index
        for (int i = 1; i <= maxJump && index + i < nums.size(); ++i) {
            int jumps = jumpHelper(nums, index + i, dp);
            if (jumps != INT_MAX) {
                minJumps = min(minJumps, 1 + jumps);  // Take the minimum jumps
            }
        }
        
        // Store the result in the dp array and return it
        return dp[index] = minJumps;
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);  // Memoization array initialized to -1
        return jumpHelper(nums, 0, dp);
    }
};