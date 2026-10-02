class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n= operations.size();
        int total_sum=0;
        stack<int>st;
        for(int i=0; i<n;i++){
            string s=operations[i];
            if(s=="+"){
                int top=st.top();
                st.pop();
                int new_top=top +st.top();
                st.push(top);
                st.push(new_top);
                total_sum+=new_top;
            }
            else if(s=="C"){
                total_sum-=st.top();
                st.pop();
            }
            else if(s=="D"){
                st.push(2*st.top());
                total_sum+=st.top();
            }
            else{
                st.push(stoi(s));
                total_sum+=st.top();
            }
        }
        return total_sum;
    }
};