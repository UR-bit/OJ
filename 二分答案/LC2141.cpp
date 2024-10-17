class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long tot = accumulate(batteries.begin(), batteries.end(), 0LL);
        long long r = tot / n;
        long long l = 0;
        long long mid = 0;
        long long sum = 0;
        while (l <= r) {
            mid = (l + r) / 2;
            sum = 0;
            for (long long x : batteries) {
                sum += min(static_cast<long long>(x), mid);
            } 
            if (n * mid <= sum) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
};
