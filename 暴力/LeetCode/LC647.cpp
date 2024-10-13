class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = n;
        for (int i = 1; i < n - 1; i++) {
            for (int j = i - 1, k = i + 1; j >= 0 && k < n; j--, k++) {
                if (s[k] == s[j]) ans++;
                else break;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i+1]) {
                ans++;
                for (int j = i - 1, k = i + 2; j >= 0 && k < n; j--, k++) {
                    if (s[k] == s[j]) ans++;
                    else break;
                }
            }
        }
        return ans;
    }
};
