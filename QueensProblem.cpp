#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> &board, int row, int col)
{
  int duplicateRow = row;
  int duplicateCol = col;
  // cout << "Intially the number of row is:" << duplicateRow << endl;
  // cout << "Intially the number of col is:" << duplicateCol << endl;

  while (row >= 0 && col >= 0)
  {
    if (board[row][col] == 'Q')
      return false;
    row--;
    col--;
    // cout << "row value in while loop" << row << endl;
    // cout << "col value in while loop" << col << endl;
  }

  row = duplicateRow;
  col = duplicateCol;

  while (col >= 0)
  {
    if (board[row][col] == 'Q')
      return false;
    col--;
    // cout << "col value only" << col << endl;
  }

  col = duplicateCol;

  while (row < board.size() && col >= 0)
  {
    if (board[row][col] == 'Q')
      return false;
    row++;
    col--;
  }

  return true;
};

void solve(vector<vector<string>> &ans, vector<string> &board, int n, int col)
{
  if (col == n)
  {
    ans.push_back(board);
    return;
  }

  for (int row = 0; row < n; row++)
  {
    if (isSafe(board, row, col))
    {
      board[row][col] = 'Q';
      solve(ans, board, n, col + 1);
      board[row][col] = '.';
    }
  }
}

int main()
{
  int n;
  cout << "Enter the size of Board: ";
  cin >> n;
  vector<vector<string>> ans;
  vector<string> board(n, string(n, '.'));

  solve(ans, board, n, 0);

  cout << "Number of Solution for the given " << n << " x " << n << " chess board is : \n";

  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << ans[i][j] << "\n";
    }
    cout << "\n";
  }
  return 0;
}