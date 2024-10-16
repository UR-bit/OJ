#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<string> strList;
vector<vector<int>> graph;

int bfs(int& n) {
    queue<vector<int>> que;
    que.push(vector<int>({0, 1}));
    while(!que.empty()){
        vector<int> cur = que.front();
        que.pop();
        for (int i = 0; i < n; i++) {
            if (graph[cur[0]][i]) {
                if (i == 1) {
                    return cur[1]+1;
                }
                graph[cur[0]][i] = 0;
                que.push(vector<int>({i, cur[1]+1}));
            }
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    n += 2;
    strList = vector<string>(n);
    graph = vector<vector<int>>(n, vector<int>(n, 0));
    cin >> strList[0] >> strList[1];
    int m = strList[0].size();
    int temp = 0;
    for (int i = 0; i < m ; i++) {
        if (strList[0][i] != strList[1][i]) {
            temp++;
        }
    }
    if (temp == 1 || temp == 0) {
        cout << 2;
        return 0;
    }

    for (int i = 2; i < n; i++) {
        cin >> strList[i];
        for (int j = 0; j < i; j++) {
            temp = 0;
            for (int k = 0; k < m ; k++) {
                if (strList[i][k] != strList[j][k]) {
                    temp++;
                }   
            }
            if (temp == 1) {
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
    }
    cout << bfs(n);
    system("pause");
    return 0;
}
