class Solution {
public:
    string minWindow(string s, string t) {        
        if (t.empty()) return "";
        unordered_map<char,int> countT, window;
        for(char c : t){
            countT[c]++;
        }

        int have =0, need =countT.size();
        int resLen= INT_MAX;
        int resStart = 0;
        int l=0;

        for(int r=0; r<s.length(); r++){
            char c =s[r];
            window[c]++;
             
            if(countT.count(c) && countT[c]== window[c]){
                have++;
            }

            while(need==have){
                if((r-l+1)<resLen){
                    resLen=r-l+1;
                    resStart = l;

                }

                window[s[l]]--;
                if(countT.count(s[l])  && window[s[l]]< countT[s[l]]){
                    have--;
                }
                l++;
            }
        }

        return resLen== INT_MAX ? "" : s.substr(resStart, resLen); 
    }
};
