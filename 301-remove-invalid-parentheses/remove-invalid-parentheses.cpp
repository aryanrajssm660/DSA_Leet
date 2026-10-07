class Solution {
public:
    unordered_set<string> st;

    void solve(string& s, int index, int leftRemove,
               int rightRemove, int balance, string& cur) {

        if (index == s.size()) {
            if (leftRemove == 0 &&
                rightRemove == 0 &&
                balance == 0) {
                st.insert(cur);
            }
            return;
        }

        char ch = s[index];

        // Remove '('
        if (ch == '(' && leftRemove > 0) {
            solve(s, index + 1, leftRemove - 1,
                  rightRemove, balance, cur);
        }

        // Remove ')'
        if (ch == ')' && rightRemove > 0) {
            solve(s, index + 1, leftRemove,
                  rightRemove - 1, balance, cur);
        }

        // Keep current character
        if (ch == '(') {
            cur.push_back(ch);

            solve(s, index + 1, leftRemove,
                  rightRemove, balance + 1, cur);

            cur.pop_back();
        }

        else if (ch == ')') {

            // Cannot keep ')' if there is no '('
            if (balance > 0) {
                cur.push_back(ch);

                solve(s, index + 1, leftRemove,
                      rightRemove, balance - 1, cur);

                cur.pop_back();
            }
        }

        else {
            // Alphabet character
            cur.push_back(ch);

            solve(s, index + 1, leftRemove,
                  rightRemove, balance, cur);

            cur.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        for (char ch : s) {

            if (ch == '(') {
                leftRemove++;
            }

            else if (ch == ')') {

                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        string cur;

        solve(s, 0, leftRemove, rightRemove, 0, cur);

        return vector<string>(st.begin(), st.end());
    }
};