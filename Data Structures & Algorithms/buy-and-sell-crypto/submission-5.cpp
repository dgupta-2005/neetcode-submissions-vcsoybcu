class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // int l=0, r=1;
        // int max_prof=0;
        // while (r<n){
        //     if(prices[l]<=prices[r]){
        //         int profit =prices[r]-prices[l];
        //         max_prof=max(max_prof,profit);
        //     }
        //     else{
        //         l=r;
        //     }
        //     r++;
        // }
        // return max_prof;
        // now using dynamic programming :
        int max_prof=0;
        int min_sell=prices[0];
        for(int i=0; i<n;i++){
            max_prof=max(max_prof,prices[i]-min_sell);
            min_sell=min(min_sell, prices[i]);
        }
        return max_prof; 
    }
};
