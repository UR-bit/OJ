#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& island, int& ans, int& n, int& m, int i, int j) {
    island[i][j] = 2;
    if (!island[i-1][j]) ans++;
    if (!island[i+1][j]) ans++;
    if (!island[i][j-1]) ans++;
    if (!island[i][j+1]) ans++;
    if (i >= 1 && island[i-1][j] == 1) dfs(island, ans, n, m, i-1, j);
    if (i <= n && island[i+1][j] == 1) dfs(island, ans, n, m, i+1, j);
    if (j >= 1 && island[i][j-1] == 1) dfs(island, ans, n, m, i, j-1);
    if (j <= m && island[i][j+1] == 1) dfs(island, ans, n, m, i, j+1);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> island(n + 2, vector<int>(m + 2, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> island[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (island[i][j] == 1) {
                dfs(island, ans, n, m, i, j);
            }
        }
    }
    cout << ans;
    return 0;
}
