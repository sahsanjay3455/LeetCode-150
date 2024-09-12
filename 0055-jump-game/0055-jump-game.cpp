class Solution {
public:
    // Helper function for memoization
    bool canJumpFromPosition(int position, vector<int>& nums, vector<int>& memo) {
        // Base case: If we've reached the last index, return true
        if (position >= nums.size() - 1) return true;
        
        // Check if this position has been computed before
        if (memo[position] != -1) return memo[position];

        // Maximum jump length from current position
        int maxJump = nums[position];
        
        // Explore all possible jumps from the current position
        for (int i = 1; i <= maxJump; ++i) {
            if (canJumpFromPosition(position + i, nums, memo)) {
                memo[position] = 1;  // Mark this position as reachable
                return true;
            }
        }

        memo[position] = 0;  // Mark this position as not reachable
        return false;
    }

    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);  // Initialize memoization table with -1
        return canJumpFromPosition(0, nums, memo);  // Start from position 0
    }
};