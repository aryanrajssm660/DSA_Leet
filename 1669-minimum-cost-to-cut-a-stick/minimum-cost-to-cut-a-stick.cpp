class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        int m = cuts.size();

        vector<vector<int>> dp(m, vector<int>(m, 0));

        for(int start = m - 2; start >= 0; start--) {
            for(int end = start + 2; end < m; end++) {

                int ans = 1e8;

                for(int i = start + 1; i < end; i++) {
                    int curr = cuts[end] - cuts[start]
                             + dp[start][i]
                             + dp[i][end];

                    ans = min(ans, curr);
                }

                dp[start][end] = ans;
            }
        }

        return dp[0][m - 1];
    }
};