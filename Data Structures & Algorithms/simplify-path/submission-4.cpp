class Solution {
public:
    string simplifyPath(string path) {
        vector<string>st;
        string curr="";
        for(char c : path+ '/'){
            if(c=='/'){
                if(curr==".."){
                    if(!st.empty()){
                        st.pop_back();
                    }
                }
                else if(!curr.empty() && curr!="."){
                    st.push_back(curr);
                }
                curr.clear();
            }
            else{
                curr+=c;
            }
        }
        string res="";
        if(st.empty()){
            return "/";
        }
        for(int i=0;i<st.size();i++){
            string s= "/"+st[i];
            res+=s;
        }
        return res;
    }
};