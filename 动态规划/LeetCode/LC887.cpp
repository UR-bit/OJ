class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for (int i = 1; ; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + 1;
            }
            if (dp[i][k] >= n) {
                return i;
            }
        }
    }
};
