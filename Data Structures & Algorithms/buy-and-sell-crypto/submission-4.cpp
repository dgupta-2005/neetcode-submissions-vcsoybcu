class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int l=0, r=1;
        int max_prof=0;
        while (r<n){
            if(prices[l]<=prices[r]){
                int profit =prices[r]-prices[l];
                max_prof=max(max_prof,profit);
            }
            else{
                l=r;
            }
            r++;
        }
        return max_prof;
    }
};
