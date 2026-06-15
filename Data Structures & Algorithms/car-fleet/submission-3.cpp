class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n= position.size();
        if (n == 0) return 0;
        vector<double>time_at_position(target+1, 0);
        for(int i=0; i<position.size(); i++){
            double time = (double)(target-position[i])/speed[i];
            time_at_position[position[i]]=time;
        }
        stack<double>st;
        for(int i=target; i>=0; i--){
            if(time_at_position[i]>0){
               double curr_car_time = time_at_position[i];
               if(st.empty() || curr_car_time> st.top()){
                st.push(curr_car_time);
               }
            }
        }
        return st.size();
    }
};
