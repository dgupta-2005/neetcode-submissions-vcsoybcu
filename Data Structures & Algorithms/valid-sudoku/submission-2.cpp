class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>>squares;
        for(int i=0; i<9;i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.') continue;
                pair<int, int> cell = {i/3, j/3};
                char c= board[i][j];
                if(rows[i].count(c) || cols[j].count(c) || squares[cell].count(c)){
                    return false;
                }
                rows[i].insert(c);
                cols[j].insert(c);
                squares[cell].insert(c);
            }
        }
        return true;
    }
};
