class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int>streak;
        int res=0;
        for(int num : nums){
            if(!streak[num]){
                int left= streak[num-1];
                int right= streak[num+1];
                streak[num] = left + right + 1;
                streak[num - left]= streak[num];
                streak[num + right]= streak[num];
                res= max(res, streak[num]);
            }
        }
        return res;
    }
};
