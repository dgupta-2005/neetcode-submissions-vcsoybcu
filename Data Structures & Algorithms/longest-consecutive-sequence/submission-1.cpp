class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int>streak;
        int res=0;
        for(int num : nums){
            if(!streak[num]){
                int x= streak[num-1];
                int y= streak[num+1];
                streak[num] = x + y + 1;
                streak[num - x]= streak[num];
                streak[num + y]= streak[num];
                res= max(res, streak[num]);
            }
        }
        return res;
    }
};
