class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> area(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int j = st.top();
                area[j] = heights[j] * (i - j);
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            int j = st.top();
            area[j] = heights[j] * (n - j);
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int j = st.top();
                area[j] += heights[j] * (j - i - 1);
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            int j = st.top();
            area[j] += heights[j] * j;
            st.pop();
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, area[i]);
        }
        return ans;
    }
};
