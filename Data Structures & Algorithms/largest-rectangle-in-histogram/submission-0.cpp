class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
         int n= heights.size();
        vector<int>left_most(n,0);
        vector<int>right_most(n,n-1);
        stack<int>st;

        for(int i=0; i< n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                left_most[i]= st.top()+1;
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                right_most[i]= st.top()-1;
            }
            st.push(i);
        }

        int max_area=0;
        for(int i=0; i<n; i++){
            max_area= max(max_area, heights[i] * (right_most[i]-left_most[i]+1));
        }
        return max_area;
        
    }
};
