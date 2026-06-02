class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int l=0;
        if(k==n){
            return arr;
        }
        for(int i =0; i<n; i++ ){
            if(x >arr[i]){
                l=i;
            }
        }
        int r=l+1;
        while(k!=0){
            if (l < 0) {
                r++;
            }
            else if (r >= n) {
                l--;
            }
            else if(abs(arr[l]-x) <= abs(arr[r]-x)){
                l--;
            }
            else{
                r++;
            }
            k--;
        }
        return vector<int>(arr.begin() + l +1, arr.begin() + r);
    }
};