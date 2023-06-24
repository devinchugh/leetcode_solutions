#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool findword(vector<vector<char>> &board, string word, int currpos, int row, int col)
    {
        if (currpos == word.size())
        {
            return true;
        }
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || word[currpos] != board[row][col])
        {
            return false;
        }
        board[row][col] = '*';
        bool chk = findword(board, word, currpos + 1, row + 1, col) || findword(board, word, currpos + 1, row, col + 1) || findword(board, word, currpos + 1, row - 1, col) || findword(board, word, currpos + 1, row, col - 1);

        board[row][col] = word[currpos];
        return chk;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        bool chk = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    chk = findword(board, word, 0, i, j);
                }
                if (chk)
                {
                    return true;
                }
            }
        }

        return false;
    }
};