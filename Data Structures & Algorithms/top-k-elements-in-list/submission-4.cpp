class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
// hash map for frequency counter
        unordered_map<int,int>freq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
// using bucket sort for O(n) complexity
        vector<vector<int>>buckets(n+1);
        for(auto& pair : freq){
            int element=pair.first;
            int count=pair.second;
            buckets[count].push_back(element);
        }
// getting top k frequent elements
// this nested just runs for at most N times
        vector<int>result;
        for(int i=n; i>=0;i--){
            for(int nums : buckets[i]){
                if(result.size()==k){
                    break;
                }
                result.push_back(nums);
            }
        }
        return result;
    }
};
