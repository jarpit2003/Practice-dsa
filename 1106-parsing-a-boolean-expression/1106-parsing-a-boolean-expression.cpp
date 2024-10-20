class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        
        for (char ch : expression) {
            if (ch == ',' || ch == '(') {
                // Ignore commas and opening parentheses
                continue;
            } else if (ch == 't' || ch == 'f' || ch == '!' || ch == '&' || ch == '|') {
                // Push true/false values and operators onto the stack
                st.push(ch);
            } else if (ch == ')') {
                // We've encountered a closing parenthesis, evaluate the expression within
                bool hasTrue = false, hasFalse = false;
                
                // Pop all operands within this set of parentheses
                while (st.top() == 't' || st.top() == 'f') {
                    if (st.top() == 't') hasTrue = true;
                    if (st.top() == 'f') hasFalse = true;
                    st.pop();
                }
                
                // The operator is on the top of the stack
                char op = st.top();
                st.pop();  // pop the operator
                
                // Perform the operation based on the type
                if (op == '!') {
                    // NOT operation: expects one operand, flip it
                    st.push(hasTrue ? 'f' : 't');
                } else if (op == '&') {
                    // AND operation: result is true if no 'f' was found
                    st.push(hasFalse ? 'f' : 't');
                } else if (op == '|') {
                    // OR operation: result is true if any 't' was found
                    st.push(hasTrue ? 't' : 'f');
                }
            }
        }
        
        // The result will be the only value left in the stack ('t' or 'f')
        return st.top() == 't';
    }
};
