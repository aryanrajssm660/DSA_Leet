class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> curr(amount + 1), prev(amount + 1, 1e8);

        prev[0] = 0;
        for (int j = coins[0]; j <= amount; j++) {
            if (j % coins[0] == 0) {
                prev[j] = j / coins[0];
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                int nottake = prev[j];
                int take = 1e8;
                if (j >= coins[i]) {
                    take = 1 + curr[j - coins[i]];
                }
                curr[j] = min(take, nottake);
            }
            prev = curr;
        }
        return prev[amount] == 1e8 ? -1 : prev[amount];
    }
};