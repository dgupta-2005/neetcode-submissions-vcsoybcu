class Solution {
public:
    int leastInterval(vector<char>& tasks, int n){
        vector<int> freqs(26,0);
        for(char c : tasks){
            freqs[c- 'A']++;
        }
        int max_freq= *max_element(freqs.begin(), freqs.end());
        int max_amount=0;
        for(int freq : freqs){
            if(max_freq== freq){
                max_amount++;
            }
        }
        int time=  (max_freq-1)*(n+1) + max_amount;
        return (time>tasks.size()) ? time : tasks.size();
    }
};
