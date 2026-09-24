class Solution {
public:
    // int find(int start, int end, vector<int>& nums, vector<vector<int>> dp) {
    //     if (start > end)
    //         return 0;
    //     if (dp[start][end] != -1) {
    //         return dp[start][end];
    //     }
    //     int ans = 0;

    //     for (int i = start; i <= end; i++) {
    //         int temp = nums[start - 1] * nums[i] * nums[end + 1] +
    //                    find(start, i - 1, nums, dp) +
    //                    find(i + 1, end, nums, dp);

    //         ans = max(ans, temp);
    //     }

    //     return dp[start][end] = ans;
    // }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int start = n - 2; start >= 1; start--) {
            for (int end = start; end <= n - 2; end++) {

                for (int i = start; i <= end; i++) {
                    int coins = nums[start - 1] * nums[i] * nums[end + 1] +
                                dp[start][i - 1] + dp[i + 1][end];

                    dp[start][end] = max(dp[start][end], coins);
                }
            }
        }
        return dp[1][n - 2];
    }
};