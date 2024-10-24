class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m / 2; j++) {
                int tmp = grid[i][j] + grid[n-i-1][j] + grid[i][m-j-1] + grid[n-i-1][m-j-1];
                ans += tmp <= 2 ? tmp : 4 - tmp;
            }
        }
        if (n % 2 && m % 2 && grid[n/2][m/2]) {
            ans++;
        }
        int tmp1 = 0, tmp2 = 0;
        if (m % 2) {
            for (int i = 0; i < n/2; i++) {
                if (grid[i][m/2] && grid[n-i-1][m/2]) tmp1++;
                else if (grid[i][m/2] || grid[n-i-1][m/2]) tmp2++;
            }
        }
        if (n % 2) {
            for (int i = 0; i < m/2; i++) {
                if (grid[n/2][i] && grid[n/2][m-i-1]) tmp1++;
                else if (grid[n/2][i] || grid[n/2][m-i-1]) tmp2++;
            }
        }
        if (tmp1 % 2 && !tmp2) ans += 2;
        else ans += tmp2;
        return ans;
    }
};
