class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        bool flag = false;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (flag && nums[i]) {
                ans++;
                flag = false;
            } else if (!flag && !nums[i]) {
                ans++;
                flag = true;
            }
        }
        return ans;
    }
};
