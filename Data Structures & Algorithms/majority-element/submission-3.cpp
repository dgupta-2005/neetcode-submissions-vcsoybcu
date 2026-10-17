class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=-1;
        int count=0;
        for(int num : nums){
            if(count==0){
                res=num;
            }
            count+= (res==num) ? 1 : -1;
        }
        return res;
    }
};