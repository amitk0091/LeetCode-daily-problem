class Solution {
public:
    int largestRectangleInHistogram(vector<int>& h) {
        stack<int> st;
        // remove krte time stack se calculate the rectangle form by that height
        int area = 0;
        for (int i = 0; i < h.size(); i++) {
            while (!st.empty() && h[st.top()] >= h[i]) {
                int k = st.top(), width = 1;
                st.pop();
                if (!st.empty()) {
                    width += (k - st.top() - 1);
                } else {
                    width += (k);
                }
                width += (i - k - 1);
                area = max(area, width * h[k]);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int k = st.top(), width = h.size() - k;
            st.pop();
            if (!st.empty()) {
                width += (k - st.top() - 1);
            } else {
                width += (k);
            }
            area = max(area, width * h[k]);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        // easy pizzy
        // at each level we have to find largest rectangle in histogram
        int ans = 0;
        vector<int> h(matrix[0].size());
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                h[j] += (matrix[i][j] - '0');
                if (matrix[i][j] == '0')
                    h[j] = 0;
            }
            ans = max(ans, largestRectangleInHistogram(h));
        }
        return ans;
    }
};