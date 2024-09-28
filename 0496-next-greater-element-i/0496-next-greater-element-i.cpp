class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreaterMap; // Stores the next greater element for each number in nums2
        stack<int> s; // To track elements for which we are looking for the next greater element
        
        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];
            
            // Pop elements from the stack that are smaller than or equal to the current num
            while (!s.empty() && s.top() <= num) {
                s.pop();
            }
            
            // If stack is not empty, the top of the stack is the next greater element for nums2[i]
            if (!s.empty()) {
                nextGreaterMap[num] = s.top();
            } else {
                nextGreaterMap[num] = -1; // No greater element found
            }
            
            // Push the current num onto the stack
            s.push(num);
        }
        
        // Build the result for nums1 based on the precomputed map
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreaterMap[num]);
        }
        
        return result;
    }
};
