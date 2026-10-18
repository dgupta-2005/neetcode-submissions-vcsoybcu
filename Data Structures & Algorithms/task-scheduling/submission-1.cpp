class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>count(26,0);
        for(int c : tasks){
            count[c-'A']++;
        }
        priority_queue<int>max_heap;
        for(int c: count){
            if(c>0){
                max_heap.push(c);
            }
        }
        queue<pair<int,int>>q;
        int time=0;
        while(!q.empty() || !max_heap.empty()){
            time++;
            if(max_heap.empty()){
                time=q.front().second;
            }
            else{
                int remaining_count= max_heap.top()-1;
                max_heap.pop();
                if(remaining_count >0) {
                    q.push({remaining_count, time+n});
                }
            }
            if(!q.empty() && time== q.front().second){
                max_heap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
