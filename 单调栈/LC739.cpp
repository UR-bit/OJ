class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        st.push(0);
        for (int i = 1; i < n; i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                temperatures[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            temperatures[st.top()] = 0;
            st.pop();
        }
        return temperatures;
    }
};
