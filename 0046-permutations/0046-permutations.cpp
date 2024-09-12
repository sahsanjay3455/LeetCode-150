class Solution {
public:
   void permuteHelper(vector<int>& nums, int start, vector<vector<int>>& result) {
    // Base case: when start index reaches the end of the array
    if (start == nums.size()) {
        result.push_back(nums);  // Store the current permutation
        return;
    }
    
    // Generate permutations by swapping the current index with each subsequent element
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);  // Swap the current element with the start element
        permuteHelper(nums, start + 1, result);  // Recurse for the next index
        swap(nums[start], nums[i]);  // Backtrack to restore original order
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    permuteHelper(nums, 0, result);  // Call helper function starting from index 0
    return result;
}

};