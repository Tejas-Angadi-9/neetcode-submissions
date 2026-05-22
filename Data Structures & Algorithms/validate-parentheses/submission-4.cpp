class Solution {
   public:
    bool isValid(string s) {
        if (s.size() == 0) return true;

        stack<char> st;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else {
                if (st.empty()) return false;

                char topChar = st.top();
                if (ch == ')' && topChar != '(' || ch == '}' && topChar != '{' ||
                    ch == ']' && topChar != '[') {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
