class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        for(char ch : s){
            if(ch >='A' && ch <= 'Z'){
                res+= (tolower(ch));
            }
            else if ((ch<='z' && ch>= 'a') || (ch<='9' && ch>='0')){
                res+=ch;
            }
        }
        int n= res.size();
        for(int i=0; i<n/2; i++){
            if(res[i]!=res[n-i-1]){
                return false;
            }
        }
        return true;
    }
};
