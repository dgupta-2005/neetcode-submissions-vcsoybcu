class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int r=1;
        int max_profit = 0;
        int n= prices.size();
        for(int r=0;r<n;r++){
            if(prices[l]<=prices[r]){
                int profit= prices[r]-prices[l];
                max_profit = max(max_profit,profit);
            }
            else{
                l=r;
            }
        }
        return max_profit;
    }
};
