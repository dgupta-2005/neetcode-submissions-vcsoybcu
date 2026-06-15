class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n= position.size();
        vector<double>time_at_position(target+1, 0);
        for(int i=0; i<position.size(); i++){
            double time = (double)(target-position[i])/speed[i];
            time_at_position[position[i]]=time;
        }
        double max_time=0;
        int fleet=0;

        for(int i=target; i>=0; i--){
            if(time_at_position[i]>0){
                if(time_at_position[i]>max_time){
                    fleet++;
                    max_time=time_at_position[i];
                }
            }
        }
        return fleet;
    }
};
