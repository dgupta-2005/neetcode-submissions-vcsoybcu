class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }

        vector<vector<int>>buckets(n+1);
        for(auto& pair : freq){
            int element=pair.first;
            int count=pair.second;
            buckets[count].push_back(element);
        }

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
