class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> map(10001, -1);
        stack<int> st;
        int n = nums1.size(), m = nums2.size();
        for (int i = 0; i < m; i++) {
            while (!st.empty() && st.top() < nums2[i]) {
                map[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        for (int i = 0; i < n; i++) {
            nums1[i] = map[nums1[i]];
        }
        return nums1;
    }
};
