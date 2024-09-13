class Solution {
public:
     void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // Handle the case when k is greater than the size of the array
        
        vector<int> v(n);  // Create a vector of size n
        
        // Fill the rotated array
        for (int i = 0; i < n; i++) {
            v[(i + k) % n] = nums[i];  // Correctly place the elements in rotated positions
        }
        
        // Copy the rotated result back into the original array
        nums = v;
    }
};