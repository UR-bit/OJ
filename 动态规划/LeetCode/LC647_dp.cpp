class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = n;
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                ans++;
            }
        }
        for (int i = 2; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                if (dp[j + 1][j + i - 1] && s[j] == s[j + i]) {
                    dp[j][j + i] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};
