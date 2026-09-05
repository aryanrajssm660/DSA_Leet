class Solution {
public:
    int solve(int index, int canSell, int cap,
              vector<int>& prices,
              vector<vector<vector<int>>>& dp) {

        if (index == prices.size() || cap == 0) {
            return 0;
        }

        if (dp[index][canSell][cap] != -1) {
            return dp[index][canSell][cap];
        }

        int take, skip;

        if (canSell) {
            // Sell the stock
            take = prices[index] +
                   solve(index + 1, 0, cap - 1, prices, dp);

            // Hold the stock
            skip = solve(index + 1, 1, cap, prices, dp);
        }
        else {
            // Buy the stock
            take = -prices[index] +
                   solve(index + 1, 1, cap, prices, dp);

            // Do not buy
            skip = solve(index + 1, 0, cap, prices, dp);
        }

        return dp[index][canSell][cap] = max(take, skip);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1))
        );

        return solve(0, 0, 2, prices, dp);
    }
};