class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>>max_heap;
        for(auto& point : points){
            int dist= point[0]*point[0] + point[1]*point[1];
            max_heap.push({dist, {point[0], point[1]}});
            if(max_heap.size()>k){
                max_heap.pop();
            }
        }
        vector<vector<int>>res;
        while(!max_heap.empty()){
            res.push_back({max_heap.top().second.first,max_heap.top().second.second});
            max_heap.pop();
        }
        return res;
    }
};
