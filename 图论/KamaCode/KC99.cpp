#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void dfs(vector<vector<int>>& area, int i, int j) {
        area[i][j] = 2;
        if (area[i][j+1] == 1) dfs(area, i, j+1);
        if (area[i+1][j] == 1) dfs(area, i+1, j);
        if (i && area[i-1][j] == 1) dfs(area, i-1, j);
        if (j && area[i][j-1] == 1) dfs(area, i, j-1);
    }
    int solution(vector<vector<int>>& area, int& n, int& m) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (area[i][j] == 1) {
                    dfs(area, i, j);
                    ans++;
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
