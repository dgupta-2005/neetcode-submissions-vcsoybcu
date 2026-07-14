class Solution {
public:
    string reorganizeString(string s) {
        vector<int>freq(26,0);
        for(char c : s){
            freq[c-'a']++;
        }
        priority_queue<pair<int,char>>max_heap;
        for(int i=0; i<26; i++){
            if(freq[i]>0){
                if (freq[i] > (s.size() + 1) / 2) return "";
                max_heap.push({freq[i],(char)('a'+i)});
            }
        }
        string res="";
        int prev_count=0;
        char prev_char='#';
        while(res.size()!=s.size()){
            char c=max_heap.top().second;
            int count=(max_heap.top().first) -1;
            max_heap.pop();
            res+=c;
            if(prev_count>0){
                max_heap.push({prev_count,prev_char});
            }
            prev_count= count;
            prev_char=c;
        }
        return res;
    }
};