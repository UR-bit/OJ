#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int cur) {
    visited[cur] = true;
    for (int i = 0; i < graph[cur].size(); i++) {
        if (!visited[graph[cur][i]]) dfs(graph, visited, graph[cur][i]);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> graph(n+1);
    vector<bool> visited(n+1, false);
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    dfs(graph, visited, 1);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << -1;
            system("pause");
            return 0;
        }
    }
    cout << 1;
    system("pause");
    return 0;
}
