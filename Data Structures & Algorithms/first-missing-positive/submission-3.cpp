class Solution {
public:
    int firstMissingPositive(vector<int>& nums){
        int n=nums.size();
        // marking all -ve values as 0
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                nums[i]=0;
            }
        } 
        // For each number val (using absolute value to handle already-marked cells):
        // If 1 <= val <= n:
        // If nums[val - 1] > 0, negate it.
        // If nums[val - 1] == 0, set it to -(n + 1).
        // Find the first index where nums[i] >= 0 and return i + 1., as it was never visited (we used index based hashing in the input array it self)
        // If no such index exists, return n + 1.
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
        for (int i =0; i<n; i++){
            if (nums[i]>=0){
                return i+1;
            }
        }
        return n+1;
    }
};


