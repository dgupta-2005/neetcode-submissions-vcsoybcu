/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    unordered_map<int, int>visited_index;
    int getSafe(int index, MountainArray &mountainArr){
        if (visited_index.find(index) == visited_index.end()) {
            visited_index[index] = mountainArr.get(index);
        }
        return visited_index[index];
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int  n= mountainArr.length();
        int l= 0;
        int r= n-1;
        while(l<r){
            int m1= l+ (r-l)/3;
            int m2= r- (r-l)/3;
            int val1= getSafe(m1, mountainArr);
            int val2= getSafe(m2, mountainArr);
            if(val1<val2){
                l=m1+1;
            }
            else if(val1>val2){
                r=m2-1;
            }
            else{
                l= m1+1;
                r= m2-1;
            }
        }
        int peak=l;
        int left = 0, right = peak;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = getSafe(mid, mountainArr);
            
            if (val == target) return mid; 
            else if (val < target) left = mid + 1;
            else right = mid - 1;
        }
        left = peak; 
        right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = getSafe(mid, mountainArr);
            
            if (val == target) return mid; 
            
            else if (val > target) left = mid + 1; 
            else right = mid - 1;
        }
        return -1;
    }
};