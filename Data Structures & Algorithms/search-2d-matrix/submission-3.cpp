class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int top=0;
        int bot= rows-1;
        while(top<=bot){
            int mid_row= top+ (bot-top)/2;
            if(matrix[mid_row][cols-1]<target) top=mid_row + 1;
            else if(matrix[mid_row][0]>target) bot= mid_row-1;
            else break;
        }
        if(top>bot) return false;
        int mid_row= top+ (bot-top)/2;
        int l=0;
        int r= cols-1;
        while(l<=r){
            int m= l+ (r-l)/2;
            if(matrix[mid_row][m]==target) return true;
            else if(matrix[mid_row][m]>target) r=m-1;
            else l=m+1;
        }
        return false;
    }
};
