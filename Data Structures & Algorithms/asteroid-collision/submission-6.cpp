class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>res;
        for(int a : asteroids){
            bool destroyed =false;
            while(!res.empty() && a<0 && res.back()>0 ){
                if(res.back()< -a){
                    res.pop_back();
                    continue;
                }
                else if(res.back() +a ==0){
                    destroyed=true;
                    res.pop_back();
                }
                else{
                    destroyed=true;
                }
                break;
            } 
            if(!destroyed){
                res.push_back(a);
            }
        }
        return res;
    }
};