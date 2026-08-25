class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> count;
        int n=s.size();
        int l=0;
        int r=0;

        int max_len=0;

        while(r<n && l<=r){
            count[s[r]]++;
            if(count[s[r]]==1){
                r++;
                max_len=max(max_len,r-l);
            }
            else{
                count[s[r]]--;
                count[s[l]]--;
                l++;
            }
            
        }
        return max_len;
    }
};
