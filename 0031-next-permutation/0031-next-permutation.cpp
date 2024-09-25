class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        
        // Step 1: Find the first decreasing element from the right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        // Step 2: If such an element was found
        if (i >= 0) {
            int j = n - 1;
            // Step 3: Find the element just larger than nums[i]
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            // Step 4: Swap them
            swap(nums[i], nums[j]);
        }
        
        // Step 5: Reverse the elements after index i
        reverse(nums.begin() + i + 1, nums.end());
    }
};
