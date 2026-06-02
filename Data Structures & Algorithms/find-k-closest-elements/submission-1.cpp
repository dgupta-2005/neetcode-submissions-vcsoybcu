class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
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
        if(l==n-1){
            for(int i = n - k; i < n; i++){
                result.push_back(arr[i]);
            }
            return result;
        }
        int r=l+1;
        while(k!=0){
            if (l < 0) {
                result.push_back(arr[r]);
                r++;
            }
            else if (r >= n) {
                result.push_back(arr[l]);
                l--;
            }
            else if(abs(arr[l]-x) <= abs(arr[r]-x)){
                result.push_back(arr[l]);
                l--;
            }
            else{
                result.push_back(arr[r]);
                r++;
            }
            k--;
        }
        sort(result.begin(), result.end());
        return result;
    }
};