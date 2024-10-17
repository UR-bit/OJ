class Solution {
public:
    const int mod = 1e9 + 7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int count = 0;
            for (int p = 0, q = -i; p <= k; p++, q++) {
                count += dp[i-1][p];
                if (q >= 0) {
                    count -= dp[i-1][q];
                }
                if (count >= mod) count -= mod;
                else if (count < 0) count += mod;
                dp[i][p] = count;
            }
        }
        return dp[n][k];
    }
};
