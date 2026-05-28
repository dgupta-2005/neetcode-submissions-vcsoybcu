class Solution {
public:
    void update(int index , int change, vector<int>& s1Freq,vector<int>& s2Freq, int &matched){
        if (s1Freq[index] == s2Freq[index]) matched--;
            s2Freq[index] += change;
        if (s1Freq[index] == s2Freq[index]) matched++;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int>s1Freq(26,0);
        vector<int>s2Freq(26,0);
        int n1=s1.size();
        int n2=s2.size();
        if (n1>n2){
            return false;
        }
        for(int i=0; i<n1; i++){
            s1Freq[s1[i]-'a']++;
            s2Freq[s2[i]-'a']++;
        }
        int matched=0;
        for(int i=0;i<26;i++){
            if(s1Freq[i]==s2Freq[i]) matched++;
        }
        if (matched == 26) {
            return true;
        }
        for(int r=n1;r<n2;r++){
            if(matched==26) return true; 
            update(s2[r] - 'a', 1,s1Freq, s2Freq, matched); 
            update(s2[r - n1] - 'a', -1, s1Freq, s2Freq, matched);
            if(matched==26) return true;
        }
        return false;

    }
};
