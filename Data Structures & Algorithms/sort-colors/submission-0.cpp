class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        vector<int>colors(3,0);
        for(int i=0;i<n;i++){
            colors[nums[i]]++;
        }
        int index=0;
        for(int i=0;i<3;i++){
            int count=colors[i];
            while(count-- >0){
                nums[index++]=i;
            }
        }
    }
};