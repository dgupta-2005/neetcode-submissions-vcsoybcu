class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n= profits.size();
        vector<int>capital_index(n);
        for(int i=0;i<n; i++){
            capital_index[i]=i;
        }
        sort(capital_index.begin(), capital_index.end(), [&](int a, int b){
            return capital[a] < capital[b];
        });
        priority_queue<int> max_profit;
        int idx=0;
        for(int i=0; i<k; i++){
            while(idx<n && capital[capital_index[idx]]<=w){
                max_profit.push(profits[capital_index[idx]]);
            idx++;
            }
            if(max_profit.empty()){
                break;
            }
            w+=max_profit.top();
            max_profit.pop();
        }
        return w;
    }
};