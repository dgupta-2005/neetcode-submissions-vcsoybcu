class Solution {
public:
    int maxArea(vector<int>& heights) {
        if (heights.size()==1){
            return 0;
        }
        int i=0;
        int j=heights.size()-1;
        int max_area=0;
        int curr_area=0;
        while(i<j){
                curr_area=min(heights[i], heights[j])*(j-i);
                max_area=max(curr_area, max_area);
            if(heights[i]<heights[j]){
                i++;
            }
            else{
                j--;
            }
        }

        return max_area;
    }
};
