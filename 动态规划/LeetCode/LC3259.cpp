class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        dp[0][0] = energyDrinkA[0];
        dp[0][1] = energyDrinkB[0];
        dp[1][0] = energyDrinkA[0] + energyDrinkA[1];
        dp[1][1] = energyDrinkB[0] + energyDrinkB[1];
        for (int i = 2; i < n; i++) {
            dp[i][0] = max(dp[i-1][0] + energyDrinkA[i], dp[i-2][1] + energyDrinkA[i]);
            dp[i][1] = max(dp[i-1][1] + energyDrinkB[i], dp[i-2][0] + energyDrinkB[i]);
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};
