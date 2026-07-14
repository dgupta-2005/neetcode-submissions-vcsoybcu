class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const vector<int>&a , const vector<int>& b){
            return a[1]<b[1];
        });
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<>> min_heap;
        int curr_pass=0;
        for(const auto& trip : trips ){
            auto [num_pass, start, end] = array{trip[0], trip[1], trip[2]};
            while(!min_heap.empty() && min_heap.top().first<=start){
                curr_pass-=min_heap.top().second;
                min_heap.pop();

            }
            curr_pass+= num_pass;
            if(curr_pass>capacity){
                return false;
            }
            min_heap.push({end, num_pass});
        }
        return true;
    }
};