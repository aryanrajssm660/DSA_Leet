class Solution {
public:
    bool diff(string& s1, string& s2) {
        if (s1.size() + 1 != s2.size())
            return false;

        int i = 0, j = 0;

        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) {
                i++;
            }
            j++;
        }

        return i == s1.size();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),
             [](string& a, string& b) {
                 return a.size() > b.size();
             });

        int n = words.size();
        vector<int> dp(n, 1);

        int ans = 1;

        for (int i = n-1; i >=0; i--) {
            for (int j = i+1; j < n; j++) {

                if (diff(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};