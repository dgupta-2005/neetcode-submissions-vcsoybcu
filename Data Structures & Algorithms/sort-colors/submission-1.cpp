class Solution {
public:
    void sortColors(vector<int>& tasks) {
        int low = 0;
    int mid = 0;
    int high = tasks.size() - 1;

    while (mid <= high) {
        if (tasks[mid] == 0) {
            swap(tasks[low++], tasks[mid++]);
        } else if (tasks[mid] == 1) {
            mid++;
        } else { // tasks[mid] == 2
            swap(tasks[mid], tasks[high--]);
        }
    }
    }
};