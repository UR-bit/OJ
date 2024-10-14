#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void dfs(vector<vector<int>>& area, int i, int j, int& n, int& m, int& tmp) {
        if (i == 0 || j == 0 || i == n - 1 || j == m - 1) tmp = -1;
        if (tmp != -1) {
            tmp++;
        }
        area[i][j] = 2;
        if (area[i][j+1] == 1) dfs(area, i, j+1, n, m, tmp);
        if (area[i+1][j] == 1) dfs(area, i+1, j, n, m, tmp);
        if (i && area[i-1][j] == 1) dfs(area, i-1, j, n, m, tmp);
        if (j && area[i][j-1] == 1) dfs(area, i, j-1, n, m, tmp);
    }
    int solution(vector<vector<int>>& area, int& n, int& m) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (area[i][j] == 1) {
                    int tmp = 0;
                    dfs(area, i, j, n, m, tmp);
                    tmp = tmp == -1 ? 0 : tmp;
                    ans += tmp;
                }
            }
        }
        return ans;
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
    cout << s.solution(area, n, m);
    system("pause");
    return 0;
}
