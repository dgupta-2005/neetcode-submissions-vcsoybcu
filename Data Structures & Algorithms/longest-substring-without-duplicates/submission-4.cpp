class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>count;
        int l=0;
        int r=0;
        int max_length=0;
        while(r<n && l<=r){
            count[s[r]]++;
            if(count[s[r]]==1){
                max_length=max(max_length, r-l+1);
                r++;
            }
            else{
                count[s[l]]--;
                count[s[r]]--;
                l++;
            }
        }
        return max_length;
    }
};
