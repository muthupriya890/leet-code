#include <stdbool.h>
#include <string.h>
bool dfs(char** board, int maxRows, int maxCols, int r, int c, char* word, int index) {
    if (word[index] == '\0') {
        return true;
    }
    if (r < 0 || r >= maxRows || c < 0 || c >= maxCols || board[r][c] != word[index]) {
        return false;
    }
    char temp = board[r][c];
    board[r][c] = '#';
    bool found = dfs(board, maxRows, maxCols, r + 1, c, word, index + 1) ||
                 dfs(board, maxRows, maxCols, r - 1, c, word, index + 1) ||
                 dfs(board, maxRows, maxCols, r, c + 1, word, index + 1) ||
                 dfs(board, maxRows, maxCols, r, c - 1, word, index + 1);
                 board[r][c] = temp;
    
    return found;
}
bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int maxRows = boardSize;
    int maxCols = boardColSize[0];
    for (int r = 0; r < maxRows; r++) {
        for (int c = 0; c < maxCols; c++) {
            
            if (board[r][c] == word[0]) {
                if (dfs(board, maxRows, maxCols, r, c, word, 0)) {
                    return true;
                }
            }
        }
    }
    
    return false;
}
