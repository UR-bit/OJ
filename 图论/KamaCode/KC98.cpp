#include <iostream>
#include <vector>

using namespace std;

struct Node{
    vector<int> next;
};

class Solution{
public:
    vector<int> ans;
    void solution(vector<Node>& node, int& n, int cur, bool& flag) {
        if (cur == n) {
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] << " ";
            }
            cout << n << endl;
            flag = true;
            return;
        }
        ans.push_back(cur);
        int m = node[cur].next.size();
        for (int i = 0; i < m; i++) {
            solution(node, n, node[cur].next[i], flag);
        }
        ans.pop_back();
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Node> node(n + 1);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        node[a].next.push_back(b);
    }
    Solution s;
    bool flag = false;
    s.solution(node, n, 1, flag);
    if (!flag) cout << -1;
    system("pause");
    return 0;
}
