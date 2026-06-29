class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using PI = pair<int , pair<int,int>>;
        priority_queue<PI, vector<PI>, greater<PI>> min_heap;
        for( auto& point : points){
            int dist = point[0]* point[0] + point[1]* point[1];
            min_heap.push({dist, {point[0],point[1]}});
        }
        vector<vector<int>>res;
        for(int i=0; i< k; i++){
            res.push_back({min_heap.top().second.first, min_heap.top().second.second});
            min_heap.pop();
        }
        return res;
    }
};
