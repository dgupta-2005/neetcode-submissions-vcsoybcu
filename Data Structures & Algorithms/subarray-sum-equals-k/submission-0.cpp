class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int res=0, curr_sum=0;
        unordered_map<int,int>prefix_sum;
        prefix_sum[0]=1;
        for(int i=0;i<n;i++){
            curr_sum+=nums[i];
            int target=curr_sum-k;
            res+=prefix_sum[target];
            prefix_sum[curr_sum]++;
        }
        return res;
    }
};