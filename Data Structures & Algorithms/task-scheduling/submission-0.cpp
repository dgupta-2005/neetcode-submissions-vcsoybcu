class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>count(26,0);
        for(char c : tasks){
            count[c-'A']++;
        }

        priority_queue<int>max_heap;
        for(int c: count){
            if(c>0){
                max_heap.push(c);
            }
        }
        
        int cycle=0;
        queue<pair<int,int>> q;
        while(!max_heap.empty() || !q.empty()){
            cycle++;
            if(max_heap.empty()){
                cycle=q.front().second;
            }
            else{
                int remain_count=max_heap.top()-1;
                max_heap.pop();
                if(remain_count>0){
                    q.push({remain_count, cycle+n});
                }
            }

            if(!q.empty() && q.front().second == cycle ){
                max_heap.push(q.front().first);
                q.pop();
            }
        }
        return cycle;
    }
};
