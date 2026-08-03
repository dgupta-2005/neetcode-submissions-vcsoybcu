class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(), piles.end());
        int res=high;
        while(low<=high){
            int k= low+ (high-low)/2;
            int total_time=0;
            for(int pile: piles){
                total_time += (pile +k -1)/k;
            }
            if(total_time <=h){
                res=k;
                high=k-1;
            }
            else{
                low=k+1;
            }
        }
        return res;
    }
};
