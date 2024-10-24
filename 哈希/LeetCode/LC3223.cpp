class Solution {
public:
    int minimumLength(string s) {
        int dict[26];
        int ans = 0;
        for (auto& c : s) {
            int t = c - 'a';
            dict[t] = dict[t] < 2 ? dict[t] + 1 : 1;
        }
        for (auto& t : dict) {
            ans += t;
        }
        return ans;
    }
};
