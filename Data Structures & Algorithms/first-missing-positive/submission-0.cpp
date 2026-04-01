class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                nums[i]=0;
            }
        }
        
        for(int i=0; i<n;i++){
            int v=abs(nums[i]);
            if(v>=1 && v<=n){
                if(nums[v-1]>0){
                    nums[v-1]*=-1;
                }
                else if(nums[v-1]==0){
                    nums[v-1]=-1*(n+1);
                }
            }
        }
        for (int i =1; i<=n; i++){
            if (nums[i-1]>=0){
                return i;
            }
        }
        return n+1;
    }
};