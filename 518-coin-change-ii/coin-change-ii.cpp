class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);

        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0) {
                prev[j] = 1;
            }
        }
        for (int i = 1; i < n; i++) {

            vector<int> curr(amount + 1, 0);
            curr[0] = 1;
            for (int j = 1; j <= amount; j++) {
                size_t notake = prev[j];
                size_t take = 0;
                if (j >= coins[i]) {
                    take = curr[j - coins[i]];
                }
                curr[j] = take + notake;
            }
            prev = curr;
        }
        return prev[amount];
    }
};