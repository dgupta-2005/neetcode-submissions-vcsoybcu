class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>freq;
        int l=0,r=0;
        int max_freq=0;
        int n= s.size();
        int window_size=0;
        int max_len=0;
        while(r<n && l<=r){
            freq[s[r]]++;
            max_freq=max(max_freq, freq[s[r]]);
            while((r-l+1)-max_freq > k){
                freq[s[l]]--;
                l++;
            }
            max_len=max(max_len,r-l+1);
            r++;
        }
        return max_len;
    }
};
