class Solution {
public:
    int solve(int index, int Isbuy, vector<int>& prices,
              vector<vector<int>>& dp) {
        if (index >= (int)prices.size()) {
            return 0;
        }
        if (dp[index][Isbuy] != -1) {
            return dp[index][Isbuy];
        }
        // if previously some stok buy
        int take, notake;
        if (Isbuy) {
            take = prices[index] + solve(index + 1, 0, prices, dp);
            notake = solve(index + 1, 1, prices, dp);
        } else {
            take = -prices[index] + solve(index + 1, 1, prices, dp);
            notake = solve(index + 1, 0, prices, dp);
        }
        return dp[index][Isbuy] = max(take, notake);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 0, prices, dp);
    }
};