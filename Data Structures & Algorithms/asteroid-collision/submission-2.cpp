class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arrows) {
        vector<int> stack;

    for (int arrow : arrows) {
        bool destroyed = false;

        // Collision happens only if top moves right (> 0) and incoming moves left (< 0)
        while (!stack.empty() && stack.back() > 0 && arrow < 0) {
            int topPower = stack.back();
            int incomingPower = -arrow;

            if (topPower < incomingPower) {
                stack.pop_back(); // Top arrow destroyed, incoming continues
            } else if (topPower == incomingPower) {
                stack.pop_back(); // Both arrows destroyed
                destroyed = true;
                break;
            } else {
                destroyed = true; // Incoming arrow destroyed
                break;
            }
        }

        if (!destroyed) {
            stack.push_back(arrow);
        }
    }

    return stack;
    }
};