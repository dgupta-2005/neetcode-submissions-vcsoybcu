class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res="";
        priority_queue<pair<int,char>>max_heap;
        if(a>0) max_heap.push({a,'a'});
        if(b>0) max_heap.push({b,'b'});
        if(c>0) max_heap.push({c,'c'});
        while(!max_heap.empty()){
            auto [count1, c1]= max_heap.top();
            max_heap.pop();
            if(res.size()>1 && res[res.size()-1]==c1 && res[res.size()-2]==c1){
                if(max_heap.empty()) break;
                auto [count2,c2]=max_heap.top();
                max_heap.pop();
                res+=c2;
                count2--;
                if(count2>0) max_heap.push({count2, c2});
                max_heap.push({count1,c1});
            }
            else{
                res+=c1;
                count1--;
                if(count1>0) max_heap.push({count1,c1});
            }
        }
        return res;
    }
};