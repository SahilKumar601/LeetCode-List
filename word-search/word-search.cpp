class Solution {
public:
    int m, n;
    vector<int> row = {1, 0, -1, 0};
    vector<int> col = {0, -1, 0, 1};

    bool solve(vector<vector<char>>& board, string &word, int i, int j, int idx) {
        if (idx == word.length()) return true;
        if (i >= m || i < 0 || j >= n || j < 0 || board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '$'; // Mark as visited

        for (int k = 0; k < 4; k++) {
            int rows = row[k] + i;
            int cols = col[k] + j;
            if (solve(board, word, rows, cols, idx + 1)) {
                return true;
            }
        }

        board[i][j] = temp; // Restore original value
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && solve(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};