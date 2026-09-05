class Solution {
public:
    int find(int index, int CanSell, int k, vector<int>& prices,
    vector<vector<vector<int>>> &dp) {
        if (index == prices.size() || k == 0) {
            return 0;
        }
        if(dp[index][CanSell][k]!=-1){
            return dp[index][CanSell][k];
        }
        if (CanSell) {
            int Sell = prices[index] + find(index + 1, 0, k - 1, prices,dp);
            int hold = find(index + 1, 1, k, prices,dp);
            return dp[index][CanSell][k]=max(Sell, hold);
        } else {
            int buy = -prices[index] + find(index + 1, 1, k, prices,dp);
            int hold = find(index + 1, 0, k, prices,dp);
            return dp[index][CanSell][k]=max(buy, hold);
        }
        return 0;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,
                                       vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return find(0, 0, k, prices,dp);
    }
};