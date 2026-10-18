class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n= tasks.size();
        for(int i=0; i<n ; i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());
        vector<int>process_index;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> min_heap;
        int i=0;
        int time=tasks[0][0];
        while(i< n || !min_heap.empty()){
            while(i < n && time >= tasks[i][0]){
                min_heap.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            if(min_heap.empty()){
                time= tasks[i][0];
            }
            else {
                auto pair = min_heap.top();
                int process_time= pair.first;
                int index= pair.second;
                min_heap.pop();
                time+=process_time;
                process_index.push_back(index);
            }
        }
        return process_index;
    }
};