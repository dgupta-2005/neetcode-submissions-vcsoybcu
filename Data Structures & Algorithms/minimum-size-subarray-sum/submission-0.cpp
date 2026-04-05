class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, r=0;
        int n=nums.size();
        int curr_sum=0;
        int wind_size=n+1;
        while(r<n){
            curr_sum+=nums[r];
            while(curr_sum>=target){
                //  updating the window size based on the target constraint 
                // updating the window size
                wind_size= min(wind_size, r-l+1);
                curr_sum -= nums[l];
                l++;
            }
            r++;
        }
        //  
        return (wind_size>n) ? 0 : wind_size;
    }
};