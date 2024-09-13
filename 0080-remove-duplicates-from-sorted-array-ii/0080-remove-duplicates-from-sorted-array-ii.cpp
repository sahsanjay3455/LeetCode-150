class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;  // If the size of the array is <= 2, no need to process further

        int i = 2;  // Start from the third element
        for (int j = 2; j < n; j++) {
            // If the current element is different from nums[i-2], it's a valid element
            if (nums[j] != nums[i-2]) {
                nums[i] = nums[j];
                i++;
            }
        }
        
        return i;  // Return the length of the array with at most two duplicates
    }
};