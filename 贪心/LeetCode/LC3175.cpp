class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        int ans = 0;
        if (k >= n) {
            for (int i = 1; i < n; i++) {
                ans = skills[ans] < skills[i] ? i : ans;
            }
        } else {
            for (int i = 1, j = 0; i < n; i++) {
                if (skills[ans] < skills[i]) {
                    j = 1;
                    ans = i;
                } else {
                    j++;
                }
                if (j == k) break;
            }
        }
        return ans;
    }
};
