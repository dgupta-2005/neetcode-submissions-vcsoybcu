class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n= position.size();
        vector<double>time_at_position(target+1, 0);
        for(int i=0; i<n;i++){
            double p=position[i];
            double s=speed[i];
            time_at_position[p]=(target-p)/s;
        }
        stack<double>st;
        for(int i=0;i<=target;i++){
            double curr_time=time_at_position[i];
            if(curr_time>0){
                while(!st.empty() && curr_time>=st.top()){
                    st.pop();
                }
                st.push(curr_time);
            }
        }
        return st.size();
    }
};
