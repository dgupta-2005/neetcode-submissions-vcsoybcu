class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int>wow;
        for(int i=0;i<nums.size();i++){
            if(wow.find(nums[i])!=wow.end() && i-wow[nums[i]]<=k){
                return true;
            }
            wow[nums[i]]=i;
        }
        return false;
    }
};