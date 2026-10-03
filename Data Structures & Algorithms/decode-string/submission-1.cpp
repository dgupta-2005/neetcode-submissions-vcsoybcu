class Solution {
public:
    string decodeString(string s) {
        stack<string>st_str;
        stack<int>st_int;
        int k=0;
        string curr="";
        for(char c: s){
            if(isdigit(c)) k= k*10 + (c-'0');
            else if(c=='['){
                st_str.push(curr);
                st_int.push(k);
                curr="";
                k=0;
            }
            else if(c==']'){
                string temp=curr;
                curr=st_str.top();
                int count=st_int.top();
                st_str.pop();
                st_int.pop();
                for(int i=0; i<count;i++){
                    curr+=temp;
                }
            }
            else{
                curr+=c;
            }
        }
        return curr;
    }
};