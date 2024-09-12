class Solution {
public:
 // Helper function to generate permutations
    void permuteHelper(vector<int>& nums, int start, set<vector<int>>& result) {
        // Base case: if start index reaches the end of the array
        if (start == nums.size()) {
            result.insert(nums);  // Store the current permutation
            return;
        }

        // Generate permutations by swapping the current index with each subsequent element
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);  // Swap the current element with the start element
            permuteHelper(nums, start + 1, result);  // Recurse for the next index
            swap(nums[start], nums[i]);  // Backtrack to restore original order
        }
    }

    // Main function to get unique permutations
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> result;  // Set to store unique permutations
        permuteHelper(nums, 0, result);  // Call helper function starting from index 0

        // Convert set to vector for the result
        return vector<vector<int>>(begin(result), end(result));
    }
};