class Solution {
    int find(vector<int>& nodes, int x) {
        return nodes[x] == -1 ? x : find(nodes, nodes[x]);
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> nodes(n + 1, -1);
        vector<int> degree(n + 1, 0);
        for (auto& p : edges) {
            degree[p[1]]++;
        }
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            if (degree[i] == 2) {
                flag = i;
            }
        }
        if (flag) {
            vector<vector<int>> e;
            for (auto& p : edges) {
                if (p[1] == flag) {
                    e.push_back(vector<int>({p[0], p[1]}));
                } else {
                    int x = find(nodes, p[0]);
                    int y = find(nodes, p[1]);
                    nodes[y] = x;
                }
            }
            if (e[0][0] == e[1][0]) {
                return e[1];
            } else {
                if (find(nodes, e[0][0]) == e[0][1]) {
                    return e[0];
                } else if (find(nodes, e[1][0]) == e[1][1]) {
                    return e[1];
                } else {
                    return e[1];
                }
            }
        } else {
            for (auto& p : edges) {
                int x = find(nodes, p[0]);
                int y = find(nodes, p[1]);
                if (x == y) return p;
                nodes[y] = x;
            }
        }
        return edges[n-1];
    }
};
