class Solution {
public:
    void sortColors(vector<int>& tasks) {
        int low =0;
  int mid=0;
  int high =tasks.size()-1;
  
  while(mid<=high){
    if(tasks[mid]==0){
      swap(tasks[low],tasks[mid]);
      low++;
      mid++;
    }
   else if(tasks[mid]==2){
      swap(tasks[mid],tasks[high]);
      high--;
    }
    else{
      mid++;
    }
  }
    }
};