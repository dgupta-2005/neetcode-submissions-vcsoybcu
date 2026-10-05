class Solution {
public:
    vector<vector<int>>dp;
    vector<vector<int>>dir= {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int dfs(vector<vector<int>>& matrix, int r, int c, int prev_val){
        int m=matrix.size(), n=matrix[0].size();
        if(r<0 || r>=m || c<0 || c>=n || matrix[r][c] <=prev_val){
            return 0;
        } 
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int res= 1;
        for(const auto& d: dir){
            res= max(res, 1+ dfs(matrix, r+d[0], c+ d[1],matrix[r][c]));
        }
        dp[r][c]=res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        dp= vector<vector<int>>(m, vector<int>(n,-1));
        int LIP =0;
        for(int r=0; r< m; r++){
            for(int c=0; c<n; c++){
                LIP = max(LIP, dfs(matrix, r, c, INT_MIN));
            }
        }
        return LIP;
    }
};
