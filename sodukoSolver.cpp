// Leetcode Problem :- 37

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board, 0, 0);
    }
    bool sudokuSolver(vector<vector<char>>& board, int currentRow, int currentCol){
        if(currentRow == board.size())
            return true;
        // Checking for row and column
        int nextRow, nextCol;
        if(currentCol == 8){
            nextRow = currentRow + 1;
            nextCol = 0;
        }
        else{
            nextRow = currentRow;
            nextCol = currentCol + 1;
        }
        
        // Recursive Function
        if(board[currentRow][currentCol] != '.')
            return sudokuSolver(board, nextRow, nextCol);
        for(char value = '1'; value <= '9'; value++){
                if(isValid(board, currentRow, currentCol,value)){
                    board[currentRow][currentCol] = value;
                    if(sudokuSolver(board, nextRow, nextCol) == true)
                        return true;
                    board[currentRow][currentCol] = '.';
                }
            }
        return false;
    }
    
    // Checking validity
    bool isValid(vector<vector<char>>& board, int currentRow, int currentCol, char value){
        for(int i = 0; i < 9; i++){
            if(board[currentRow][i] == value)
                return false;
            if(board[i][currentCol] == value)
                return false;
            if(board[3*(currentRow/3) + i/3][3*(currentCol/3) + i%3] == value)
                return false;    
        }
        return true;
    }
};
