class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& arrows) {
        stack<int> s;
        int i = 0;

        int n = arrows.size();
        while (i < n) {
            if (arrows[i] < 0 && !s.empty() && s.top() > 0) {
                if (s.top() + arrows[i] == 0) {
                    s.pop();
                    i++;
                } else if (s.top() + arrows[i] > 0) {
                    i++;
                } else {
                    s.pop();
                }
            }

            else {
                s.push(arrows[i++]);
            }
        }
        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};