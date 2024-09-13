class Solution {
public:
     string reverseStr(string s, int k) {
        int n = s.size();
        
        // Iterate over the string in chunks of 2k
        for (int i = 0; i < n; i += 2 * k) {
            // Reverse the first k characters in the current chunk
            int left = i;
            // Make sure to reverse only 'k' characters or until the end of the string
            int right = min(i + k - 1, n - 1);  
            
            // Standard two-pointer approach to reverse the characters
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
    }
};