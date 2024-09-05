#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(vector<int>& dp, const vector<int>& nums, int start, int end) {
        if (start > end) return 0;  // No houses to rob
        if (dp[start] != -1) return dp[start];  // Memoized result
        
        // Rob the current house and move to the next non-adjacent house
        int take = nums[start] + solve(dp, nums, start + 2, end);
        
        // Skip the current house and move to the next house
        int notTake = solve(dp, nums, start + 1, end);
        
        return dp[start] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];  // If only one house, rob it
        
        // Create two dp arrays, one for each subproblem
        vector<int> dp1(n, -1), dp2(n, -1);
        
        // Case 1: Rob from house 0 to house n-2
        int case1 = solve(dp1, nums, 0, n - 2);
        
        // Case 2: Rob from house 1 to house n-1
        int case2 = solve(dp2, nums, 1, n - 1);
        
        // Return the maximum of both cases
        return max(case1, case2);
    }
};

