class Solution {
public:
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
            if(s1Freq[i]==s2Freq[i]){
                matched++;
            }
        }
        if (matched == 26) {
            return true;
        }
        int l=0;
        for(int r=n1;r<n2;r++){
            if(matched==26){
                return true;
            } 
            int to_add_index=s2[r]-'a';
            s2Freq[to_add_index]++;
            if(s1Freq[to_add_index]==s2Freq[to_add_index]){
                matched++;
            }
            else if(s1Freq[to_add_index]+1==s2Freq[to_add_index]){
                matched--;
            }

            int to_remove_index=s2[l]-'a';
            s2Freq[to_remove_index]--;
            if(s1Freq[to_remove_index]==s2Freq[to_remove_index]){
                matched++;
            }
            else if(s1Freq[to_remove_index]-1==s2Freq[to_remove_index]){
                matched--;
            }
            l++;
            
            if (matched == 26) {
                return true;
            }
        }
        return false;

    }
};
