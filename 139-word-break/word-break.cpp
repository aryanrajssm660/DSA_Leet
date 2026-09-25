// class Solution {
// public:
//     bool find(int end, string& s, vector<string>& wordDict, vector<int>& dp) {
//         if (end == 0)
//             return true;

//         if (dp[end] != -1)
//             return dp[end];

//         for (string& word : wordDict) {
//             int len = word.size();

//             if (end >= len &&
//                 s.substr(end - len, len) == word) {

//                 if (find(end - len, s, wordDict, dp))
//                     return dp[end] = 1;
//             }
//         }

//         return dp[end] = 0;
//     }

//     bool wordBreak(string s, vector<string>& wordDict) {
//         vector<int> dp(s.size() + 1, -1);

//         return find(s.size(), s, wordDict, dp);
//     }
// };

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);

        dp[0] = true;

        for (int end = 1; end <= n; end++) {
            for (string& word : wordDict) {
                int len = word.size();

                if (end >= len &&
                    dp[end - len] &&
                    s.substr(end - len, len) == word) {
                    dp[end] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};