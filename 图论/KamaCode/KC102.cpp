#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool dfs(vector<vector<int>>& area, int i, int j, int& n, int& m) {
        bool tmp = true;
        area[i][j] = 2;
        if (area[i][j+1] == 1) tmp = tmp & dfs(area, i, j+1, n, m);
        if (area[i+1][j] == 1) tmp = tmp & dfs(area, i+1, j, n, m);
        if (i && area[i-1][j] == 1) tmp = tmp & dfs(area, i-1, j, n, m);
        if (j && area[i][j-1] == 1) tmp = tmp & dfs(area, i, j-1, n, m);
        if (i == 0 || j == 0 || i == n - 1 || j == m - 1) tmp = false;
        return tmp;
    }
    void dfs2(vector<vector<int>>& area, int i, int j) {
        area[i][j] = 0;
        if (area[i][j+1] == 2)  dfs2(area, i, j+1);
        if (area[i+1][j] == 2)  dfs2(area, i+1, j);
        if (i && area[i-1][j] == 2)  dfs2(area, i-1, j);
        if (j && area[i][j-1] == 2)  dfs2(area, i, j-1);
    }
    void solution(vector<vector<int>>& area, int& n, int& m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (area[i][j] == 1) {
                    if (dfs(area, i, j, n, m)) {
                        dfs2(area, i, j);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (area[i][j]) cout << 1;
                else cout << 0;
                cout << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> area(n+1, vector<int>(m+1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> area[i][j];
        }
    }
    Solution s;
    s.solution(area, n, m);
    system("pause");
    return 0;
}
