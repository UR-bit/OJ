class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();
        vector<long long> map(24, 0);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int a = hours[i] % 24;
            int b = (24 - a) % 24;
            ans += map[b];
            map[a]++;
        }
        return ans;
    }
};
