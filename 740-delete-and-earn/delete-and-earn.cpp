class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> mpp;

        for (auto it : nums) {
            mpp[it]++;
        }

        int size = mpp.size();
        vector<int> dp(size);

        int i = 0;
        int prev = -1;

        for (auto it : mpp) {
            int curr = it.first;
            int value = curr * it.second;

            if (i == 0) {
                dp[i] = value;
            }
            else if (curr - prev > 1) {
                dp[i] = dp[i - 1] + value;
            }
            else {
                dp[i] = value;

                if (i >= 2) {
                    dp[i] = max(dp[i], dp[i - 2] + value);
                }

                dp[i] = max(dp[i], dp[i - 1]);
            }

            prev = curr;
            i++;
        }

        return dp[size - 1];
    }
};