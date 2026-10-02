class Solution {
public:
    vector<string> ans;
    bool find(string& t) {
        stack<char> st;
        for (char ch : t) {
            if (ch == '(') {
                st.push(ch);
            } else if (!st.empty()) {
                st.pop();
            } else {
                return false;
            }
        }
        return st.empty() ? true : false;
    }
    void f(int n, int index, string& temp) {
        if (2 * n == index) {
            if (find(temp)) {
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back('(');
        f(n, index + 1, temp);
        temp.pop_back();
        temp.push_back(')');
        f(n, index + 1, temp);
        temp.pop_back();
        return ;
    }
    vector<string> generateParenthesis(int n) {
        string temp="";
        f(n,0,temp);
        return ans;
    }
};