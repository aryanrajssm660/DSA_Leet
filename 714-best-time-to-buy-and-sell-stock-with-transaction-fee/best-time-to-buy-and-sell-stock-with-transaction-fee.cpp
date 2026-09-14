class Solution {
public:
    int tax;
    int find(int index, int canbuy, vector<int>& prices,
             vector<vector<int>> &dp) {
        if (index >= prices.size()) {
            return 0;
        }
        if (dp[index][canbuy] != -1) {
            return dp[index][canbuy];
        }
        if (canbuy) {
            // 1 represent yes
            return dp[index][canbuy] =
                       max(-prices[index] + find(index + 1, 0, prices, dp),
                           find(index + 1, 1, prices, dp));
        }

        else {
            return dp[index][canbuy] = max(-tax + prices[index] +
                                               find(index + 1, 1, prices, dp),
                                           find(index + 1, 0, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        tax = fee;
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return find(0, 1, prices, dp);
    }
};