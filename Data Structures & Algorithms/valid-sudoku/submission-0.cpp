class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9, 0);
        vector<int> cols(9, 0);
        vector<int> square(9, 0);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char& c = board[i][j];

                if (c == '.') {
                    continue;
                }

                int rowId = i;
                int colId = j;
                int squId = i / 3 * 3 + j / 3;
                int charBit = (1 << (c - '1'));

                if (rows[rowId] & charBit)
                    return false;
                else
                    rows[rowId] |= charBit;

                if (cols[colId] & charBit)
                    return false;
                else
                    cols[colId] |= charBit;

                if (square[squId] & charBit)
                    return false;
                else
                    square[squId] |= charBit;
            }
        }

        return true;
    }
};

