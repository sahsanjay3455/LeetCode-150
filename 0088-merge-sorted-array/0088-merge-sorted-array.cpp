class Solution {
public:
   void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;  // Pointer for the last element in nums1's initial part
        int j = n - 1;  // Pointer for the last element in nums2
        int k = m + n - 1;  // Pointer for the last position in nums1
        
        // Iterate while there are elements in both arrays
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];  // Place nums1[i] in the correct position
                i--;
            } else {
                nums1[k] = nums2[j];  // Place nums2[j] in the correct position
                j--;
            }
            k--;  // Move to the next position
        }
        
        // If there are remaining elements in nums2, copy them to nums1
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
   }
};