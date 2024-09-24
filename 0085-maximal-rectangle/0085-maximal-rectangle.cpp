class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            // Update heights for the current row
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0; // Reset height to 0
                }
            }
            // Calculate the maximum area for the current row's histogram
            maxArea = std::max(maxArea, calculateMaxArea(heights));
        }

        return maxArea;
    }

private:
    int calculateMaxArea(std::vector<int>& heights) {
        std::stack<int> s;
        int maxArea = 0;
        heights.push_back(0); // Sentinel value

        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int h = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1; // Calculate width
                maxArea = std::max(maxArea, h * width);
            }
            s.push(i); // Push current index to the stack
        }

        heights.pop_back(); // Remove the sentinel value
        return maxArea;
    }
};
