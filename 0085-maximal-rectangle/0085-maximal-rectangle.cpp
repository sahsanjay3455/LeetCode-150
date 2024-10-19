class Solution {
public:
    // Helper function to calculate the largest rectangle area in the histogram
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int max_area = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : heights[i];
            
            // Calculate the area of the rectangle using the height at the top of the stack
            while (!s.empty() && heights[s.top()] >= h) {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                max_area = max(max_area, height * width);
            }
            s.push(i);
        }
        return max_area;
    }

    // Function to calculate the maximal rectangle
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);  // To store the height of histograms
        int max_area = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Update the histogram heights
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            // Calculate the maximum area for the current histogram
            max_area = max(max_area, largestRectangleArea(heights));
        }
        
        return max_area;
    }
};