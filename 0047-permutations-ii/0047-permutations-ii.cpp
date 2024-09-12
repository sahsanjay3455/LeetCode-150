class Solution {
public:
   
void permuteUniqueHelper(vector<int>& nums, vector<int>& current, set<vector<int>>& result, vector<bool>& used) {
    // Base case: if current permutation size is equal to the nums size
    if (current.size() == nums.size()) {
        result.insert(current);  // Store the current permutation in the set
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;  // Skip if the element is already used

        // Mark the current element as used
        used[i] = true;
        current.push_back(nums[i]);  // Add the element to the current permutation

        // Recurse for the next element
        permuteUniqueHelper(nums, current, result, used);

        // Backtrack by removing the element and marking it as unused
        current.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    set<vector<int>> result;  // Set to store unique permutations
    vector<int> current;      // Current permutation
    vector<bool> used(nums.size(), false);  // Used flags to track elements in the current permutation
    
    // Start backtracking
    permuteUniqueHelper(nums, current, result, used);
    
    // Convert set to vector for final output
    return vector<vector<int>>(result.begin(), result.end());
}

};