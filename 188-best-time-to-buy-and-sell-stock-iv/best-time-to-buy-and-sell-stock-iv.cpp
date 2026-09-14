class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        for (int index = n - 1; index >= 0; index--) {
            for (int j = 0; j < 2; j++) {
                int skip, take;
                for (int cap = 1; cap <= k; cap++) {
                    if (j) {
                        // Sell the stock
                        take = prices[index] + dp[index + 1][0][cap - 1];

                        // Hold the stock
                        skip = dp[index + 1][1][cap];
                    } else {
                        // Buy the stock
                        take = -prices[index] + dp[index + 1][1][cap];

                        // Do not buy
                        skip = dp[index + 1][0][cap];
                    }

                    dp[index][j][cap] = max(take, skip);
                }
            }
        }
        return dp[0][0][k];
    }
};