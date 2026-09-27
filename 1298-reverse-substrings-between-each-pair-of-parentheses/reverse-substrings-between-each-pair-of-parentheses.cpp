class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        for(auto ch:s){
            cout<<ch<<"  ";
            if(ch==')'){
                string temp="";
                while(st.top()!='('){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                for(auto it:temp){
                    st.push(it);
                }

            }
            else{
                st.push(ch);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};