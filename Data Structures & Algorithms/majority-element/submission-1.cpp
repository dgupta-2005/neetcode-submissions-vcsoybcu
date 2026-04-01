class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i =0; i<nums.size();i++){
            freq[nums[i]]++;
        }
        int max=0;
        for(const auto& val :freq){
            if(val.second >= (nums.size()+1)/2){
                return val.first;
            }
        }
        // int n = nums.size();

        // while (true) {
        //     int candidate = nums[rand() % n];
        //     int count = 0;
        //     for (int num : nums) {
        //         if (num == candidate) {
        //             count++;
        //         }
        //     }
        //     if (count > n / 2) {
        //         return candidate;
        //     }
        // }
    }
};