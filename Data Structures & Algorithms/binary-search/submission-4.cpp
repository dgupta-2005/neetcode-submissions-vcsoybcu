class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int n= nums.size();
        int h= n-1;
        int m= l + (h-l)/2;
        while(l<=h){
            if(nums[m]==target){
               return m; 
            }
            else if(nums[m]<target){
                l=m+1;
            }
            else{
                h=m-1;
            }
            m=l+(h-l)/2;
        }
        return -1;
    }
};
