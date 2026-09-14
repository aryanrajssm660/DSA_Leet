class Solution {
public:
    int find(int index, int canbuy, vector<int>& prices,
             vector<vector<int>>& dp) {
        if (index >= prices.size()) {
            return 0;
        }
        if(dp[index][canbuy]!=-1){
            return dp[index][canbuy];
        }
        int take, skip;
        if (canbuy == 0) {
            // zero indicates buy
            take = -prices[index] + find(index + 1, 1, prices,dp);
            skip = find(index + 1, 0, prices,dp);
        } else {
            // 1 indicate sell
            take = prices[index] + find(index + 2, 0, prices,dp);
            skip = find(index + 1, 1, prices,dp);
        }
        return dp[index][canbuy] = max(take, skip);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return find(0, 0, prices, dp);
    }
};