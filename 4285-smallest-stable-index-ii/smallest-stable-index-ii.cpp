class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minimum(n);
        int mini = nums[n - 1];
        for (int i = 0; i < n; i++) {
            mini = min(mini, nums[n - 1 - i]);
            minimum[n-i-1] = mini;
        }
        int maxi = nums[0];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(nums[i], maxi);
            if (maxi - minimum[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};