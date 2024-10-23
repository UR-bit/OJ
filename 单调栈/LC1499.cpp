class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int ans = -1e9;
        deque<int> que;
        for (int i = 0; i < n; i++) {
            while(!que.empty() && points[i][0] - points[que.front()][0] > k) {
                que.pop_front();
            }
            if (!que.empty()) {
                ans = max(ans, points[i][1] + points[i][0] + points[que.front()][1] - points[que.front()][0]);
            }
            while (!que.empty() && points[que.back()][1] - points[que.back()][0] <= points[i][1] - points[i][0]) {
                que.pop_back();
            }
            que.push_back(i);
        }
        return ans;
    }
};
