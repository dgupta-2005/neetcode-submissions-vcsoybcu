class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        unordered_map<int,int>freq;
        int n= nums.size();
        for(int num : nums){
            freq[num]++;
        }
        vector<vector<int>>buckets(n+1);
        for(auto& pair : freq){
            int element= pair.first;
            int count= pair.second;
            buckets[count].push_back(element);
        }
        vector<int>res;
        for(int i=n; i>=0; i--){
            for(int num: buckets[i]){
                if(res.size()==k){
                    break;
                }
                res.push_back(num);
            }
        }
        return res;
    }
};
