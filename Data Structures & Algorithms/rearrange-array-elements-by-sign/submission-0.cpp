class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n= nums.size();
        vector<int>res(n, 0);
        int i=0,j=1;
        for(int k=0;k<n;k++){
            if(nums[k]>0){
                res[i]=nums[k];
                i+=2;
            }
            else{
                res[j]=nums[k];
                j+=2;
            }
        }
        return res;
    }
};