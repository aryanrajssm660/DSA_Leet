class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int canbuy = 0; canbuy < 2; canbuy++) {

                int take, skip;

                if (canbuy == 0) {
                    // 0 = buy
                    take = -prices[index] + dp[index + 1][1];
                    skip = dp[index + 1][0];
                } else {
                    // 1 = sell
                    take = prices[index] + dp[index + 2][0];
                    skip = dp[index + 1][1];
                }

                dp[index][canbuy] = max(take, skip);
            }
        }

        return dp[0][0];
    }
};