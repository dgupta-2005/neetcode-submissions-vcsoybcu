class Solution {
public:
    int trap(vector<int>& height) {
        // int total_area=0;
        // int curr_area=0;
        // int curr_max=-1;
        // for (int i=0; i<height.size()-1;i++){
        //     curr_max=max(curr_max,height[i]);
        //     if(curr_max>height[i+1]){
        //         curr_area+=curr_max-height[i+1];
        //     }
        //     else {
        //         total_area+=curr_area;
        //         curr_area=0;
        //     }
        // }
        // return total_area;

        // now with the two pointers approach :
        int l=0;
        int r=height.size()-1;
        int l_max=height[l];
        int r_max=height[r];
        int area=0;
        while(l<r){
            if(l_max < r_max){
                l++;
                l_max=max(l_max, height[l]);
                area+=l_max-height[l];
            }
            else{
                r--;
                r_max=max(r_max, height[r]);
                area+=r_max- height[r];
            }
        }
        return area;
    }
};
