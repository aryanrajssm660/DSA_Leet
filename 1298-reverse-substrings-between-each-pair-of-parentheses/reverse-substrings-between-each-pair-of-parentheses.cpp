class Solution {
public:
    string reverseParentheses(string s) {
        string st;

        for (char ch : s) {
            if (ch == ')') {
                string temp;

                while (st.back() != '(') {
                    temp += st.back();
                    st.pop_back();
                }

                st.pop_back();  // remove '('

                for (char c : temp)
                    st.push_back(c);
            }
            else {
                st.push_back(ch);
            }
        }

        return st;
    }
};