#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
private:
    int largestRectangleArea(const vector<int>& heights) {
        int n = static_cast<int>(heights.size());
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; ++i) {
            int currHeight = (i == n) ? 0 : heights[i];
            while (!st.empty() && currHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int rows = static_cast<int>(matrix.size());
        int cols = static_cast<int>(matrix[0].size());
        vector<int> heights(cols, 0);
        int ans = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (matrix[r][c] == '1') {
                    heights[c] += 1;
                } else {
                    heights[c] = 0;
                }
            }
            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};