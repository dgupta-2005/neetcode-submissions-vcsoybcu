class Solution {
public:
    string decodeString(string s) {
        stack<string>str_st;
        stack<int>int_st;
        int k=0;
        string curr="";
        for( char c : s){
            if(isdigit(c))  k= k*10 + (c- '0');

            else if( c=='['){
                str_st.push(curr);
                int_st.push(k);
                curr="";
                k=0;
            }
            else if(c==']'){
                string temp= curr;
                curr= str_st.top();
                int count= int_st.top();
                str_st.pop();
                int_st.pop();
                for(int i=0;i<count; i++){
                    curr += temp;
                }
            }
            else{
                curr += c;
            }
        }
        return curr;
    }
};