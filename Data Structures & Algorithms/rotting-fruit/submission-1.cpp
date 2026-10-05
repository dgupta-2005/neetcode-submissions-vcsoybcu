class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        int m=grid.size();
        int n= grid[0].size();
        int fresh=0;
        int time=0;
        for(int i=0;i<m;i++){
            for(int j=0; j<n;j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        vector<pair<int, int>>dir= {{1, 0}, {-1,0}, {0, 1},{0,-1}};
        while( fresh >0 && !q.empty()){
            int length= q.size();
            for(int i=0; i<length; i++){
                auto curr= q.front();
                q.pop();
                int row= curr.first;
                int col= curr.second;
                for(const auto& d: dir){
                    int r= row + d.first;
                    int c= col + d.second;
                    if(r >=0 && r<m && c>=0 && c<n && grid[r][c]==1){
                        grid[r][c]=2;
                        fresh--;
                        q.push({r,c});                    }
                }
            }
            time ++;
        }
    return fresh==0 ? time :-1;
    }
};
