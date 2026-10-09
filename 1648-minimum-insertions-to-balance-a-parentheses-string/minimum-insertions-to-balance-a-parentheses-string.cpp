
class Solution {
public:
    int minInsertions(string s) {
        int left = 0, ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                left++;
            } else {
                if (i + 1 < n && s[i + 1] == ')') {
                    i++;
                } else {
                    ans++;
                }

                if (left > 0) {
                    left--;
                } else {
                    ans++;
                }
            }
        }

        return ans + 2 * left;
    }
};