class Solution {
public:
    int solve(int index, int canSell, int cap, vector<int>& prices,
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
            take = prices[index] + solve(index + 1, 0, cap - 1, prices, dp);

            // Hold the stock
            skip = solve(index + 1, 1, cap, prices, dp);
        } else {
            // Buy the stock
            take = -prices[index] + solve(index + 1, 1, cap, prices, dp);

            // Do not buy
            skip = solve(index + 1, 0, cap, prices, dp);
        }

        return dp[index][canSell][cap] = max(take, skip);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        // for(int i=0;i<2;i++){
        //     for(int j=0;j<3;j++){
        //         dp[n][i][j]=0;
        //     }
        // }
        for (int index = n - 1; index >= 0; index--) {
            for (int j = 0; j < 2; j++) {
                for (int cap = 1; cap <= 2; cap++) {
                    int take, skip;
                    if (j) {
                        // Sell the stock
                        take = prices[index] +
                               dp[index + 1][0][cap - 1];

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

        return dp[0][0][2];
    }
};