class Solution {
public:
    void evaluate(char op, stack<int>&st){
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();
        switch(op){
            case '+': st.push(b+a); break;
            case '-' : st.push(b-a); break;
            case '*' : st.push(b*a); break;
            case '/' : st.push(b/a); break;
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(const string& c : tokens){
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                evaluate(c[0], st);
            }
            else{
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};
