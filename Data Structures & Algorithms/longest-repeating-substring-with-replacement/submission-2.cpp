class Solution {
public:
    int characterReplacement(string s, int k) {
        int n= s.size();
        unordered_map<char, int> freq ;
        int res=0;
        int l=0, max_f=0;
        for(int r=0;r<n;r++){
            // maintaning the hash map
            freq[s[r]]++;
            max_f=max(max_f, freq[s[r]]);
            // while (window size - most freq chars > no.of replacements)
            while(r-l+1 - max_f > k){
                // shrinking down the window & updating the hash map
                freq[s[l]]--;
                l++;
            }
            res= max(res, r-l+1);
        }
        return res;
    }
};
