#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sea;
vector<vector<bool>> visited1;
vector<vector<bool>> visited2;
vector<vector<int>> isisland;
int n, m;

void dfs1(int i, int j, int& area) {
    visited1[i][j] = true;
    area++;
    if (i > 0 && !visited1[i-1][j] && sea[i-1][j]) dfs1(i-1, j, area);
    if (j > 0 && !visited1[i][j-1] && sea[i][j-1]) dfs1(i, j-1, area);
    if (i < n-1 && !visited1[i+1][j] && sea[i+1][j]) dfs1(i+1, j, area);
    if (j < m-1 && !visited1[i][j+1] && sea[i][j+1]) dfs1(i, j+1, area);
}

void dfs2(int i, int j, int& area, int& temp) {
    visited2[i][j] = true;
    sea[i][j] = area;
    isisland[i][j] = temp;
    if (i > 0 && !visited2[i-1][j] && sea[i-1][j]) dfs2(i-1, j, area, temp);
    if (j > 0 && !visited2[i][j-1] && sea[i][j-1]) dfs2(i, j-1, area, temp);
    if (i < n-1 && !visited2[i+1][j] && sea[i+1][j]) dfs2(i+1, j, area, temp);
    if (j < m-1 && !visited2[i][j+1] && sea[i][j+1]) dfs2(i, j+1, area, temp);
}

bool sameIsland(int i, int j, vector<int>& island) {
    for (int k = 0; k < island.size(); k++) {
        if (island[k] == isisland[i][j]) return false;
    }
    return true;
}

int solution() {
    int temp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited1[i][j] && sea[i][j]) {
                int area = 0;
                temp++;
                dfs1(i, j, area);
                dfs2(i, j, area, temp);
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!sea[i][j]) {
                int area = 1;
                vector<int> island;
                if (i > 0) {
                    area += sea[i-1][j];
                    island.push_back(isisland[i-1][j]);
                }
                if (j > 0 && sameIsland(i, j-1, island)) {
                    area += sea[i][j-1];
                    island.push_back(isisland[i][j-1]);
                }
                if (i < n-1 && sameIsland(i+1, j, island)) {
                    area += sea[i+1][j];
                    island.push_back(isisland[i+1][j]);
                }
                if (j < m-1 && sameIsland(i, j+1, island)) {
                    area += sea[i][j+1];
                    island.push_back(isisland[i][j+1]);
                }
                ans = max(ans, area);
            } else {
                ans = max(ans, sea[i][j]);
            }
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    sea = vector<vector<int>>(n, vector<int>(m, 0));
    visited1 = vector<vector<bool>>(n, vector<bool>(m, false));
    visited2 = vector<vector<bool>>(n, vector<bool>(m, false));
    isisland = vector<vector<int>>(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> sea[i][j];
        }
    }
    cout << solution();
    system("pause");
    return 0;
}
