class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int l=1;
        int r=1+(x-1)/2;
        bool found = false;
        int m= l + (r-l)/2;
        while(!found && l<=r){
            if((long long )m*m==x){
                found= true;
                break;
            }
            else if((long long)m*m > x){
                r=m-1;
            }
            else{
                l=m+1;
            }
            m= l + (r-l)/2;
        }
        return found ? m : r;
    }
};