class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> water(n, 0);
        int h = 0;
        int l = 0, r = n - 1;
        while (l < n && !height[l]) l++;
        while (r >= 0 && !height[r]) r--;
        h = l;
        for (int i = l; i < r; i++) {
            if (height[i] > height[h]) h = i;
            water[i] = height[h] - height[i];
        }
        h = r;
        for (int i = r; i >= l; i--) {
            if (height[i] > height[h]) h = i;
            water[i] = min(height[h] - height[i], water[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += water[i];
        }
        return ans;
    }
};
