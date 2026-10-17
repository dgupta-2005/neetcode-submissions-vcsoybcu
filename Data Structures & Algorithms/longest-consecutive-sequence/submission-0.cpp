class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int>streak;
        int res=0;
        for(int num : nums){
            if(!streak[num]){
                streak[num] = streak[num-1] + streak[num+1] + 1;
                streak[num - streak[num-1]]= streak[num];
                streak[num + streak[num+1]]= streak[num];
                res= max(res, streak[num]);
            }
        }
        return res;
    }
};
