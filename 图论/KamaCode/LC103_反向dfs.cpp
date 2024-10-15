#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// 反向dfs

class Solution{
public:
    void dfs(vector<vector<int>>& vec, vector<vector<bool>>& flag, int& n, int& m, int i, int j) {
        if (flag[i][j]) return;
        flag[i][j] = true;
        if (i > 0 && vec[i][j] <= vec[i-1][j]) dfs(vec, flag, n, m, i-1, j);
        if (j > 0 && vec[i][j] <= vec[i][j-1]) dfs(vec, flag, n, m, i, j-1);
        if (i < n-1 && vec[i][j] <= vec[i+1][j]) dfs(vec, flag, n, m, i+1, j);
        if (j < m-1 && vec[i][j] <= vec[i][j+1]) dfs(vec, flag, n, m, i, j+1);
    }
    void solution(vector<vector<int>>& vec, int& n, int& m) {
        vector<vector<bool>> flag1(n, vector<bool>(m, false));
        vector<vector<bool>> flag2(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            dfs(vec, flag1, n, m, i, 0);
            dfs(vec, flag2, n, m, i, m-1);
        }
        for (int j = 0; j < m; j++) {
            dfs(vec, flag1, n, m, 0, j);
            dfs(vec, flag2, n, m, n-1, j);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (flag1[i][j] && flag2[i][j]) cout << i << " " << j << endl;
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }
    Solution s;
    s.solution(vec, n, m);
    system("pause");
    return 0;
}
