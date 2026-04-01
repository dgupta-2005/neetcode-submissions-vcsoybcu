class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string word_merged="";
        int l=0;
        int r=0;
        while(l<word1.size() && r<word2.size()){
            word_merged+=word1[l++];
            word_merged+=word2[r++];
        }
            while(l<word1.size()){
                word_merged+=word1[l];
                l++;
            }
            while(r<word2.length()){
                word_merged+=word2[r];
                r++;
            }
        return word_merged;
    }
};