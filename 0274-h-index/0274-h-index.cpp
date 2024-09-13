class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n + 1, 0); // Initialize count array with n + 1 elements
        
        // Count the citations
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n) {
                count[n]++; // Group all citations >= n into one bucket
            } else {
                count[citations[i]]++;
            }
        }
        
        // Calculate the H-index
        int total = 0; // Total number of papers with at least h citations
        for (int h = n; h >= 0; h--) {
            total += count[h];
            if (total >= h) {
                return h;
            }
        }
        
        return 0;
    }
};