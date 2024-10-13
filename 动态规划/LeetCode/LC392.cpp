class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m > n) return false;
        if (m == 0) return true;
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (s[flag] == t[i]) flag++;
            if (flag == m) break;
        }
        return flag == m;
    }
};
