class Solution {
public:
    bool find(int index, string& s, int open, vector<vector<int>>& dp) {

        if (open < 0) return false;

        if (index == s.size()) {
            return open == 0;
        }

        if (dp[index][open] != -1)
            return dp[index][open];

        if (s[index] == '(') {
            return dp[index][open] = find(index + 1, s, open + 1, dp);
        }

        if (s[index] == ')') {
            return dp[index][open] = find(index + 1, s, open - 1, dp);
        }

        // '*'
        bool empty = find(index + 1, s, open, dp);
        bool opening = find(index + 1, s, open + 1, dp);
        bool closing = find(index + 1, s, open - 1, dp);

        return dp[index][open] = empty || opening || closing;
    }

    bool checkValidString(string s) {
        int n = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return find(0, s, 0, dp);
    }
};