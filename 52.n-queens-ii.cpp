/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (72.84%)
 * Likes:    3658
 * Dislikes: 250
 * Total Accepted:    343.6K
 * Total Submissions: 471.7K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 *
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 9
 *
 *
 */

// @lc code=start

#include <vector>

class Solution {
public:
  int totalNQueens(int n) {
    int result = 0;
    std::vector<int> solution(n);
    solveNQueensRecursive(n, 0, solution, result);
    return result;
  }

  void solveNQueensRecursive(int n, int currentRow, std::vector<int> &solution,
                             int &result) {
    for (int i = 0; i < n; i++) {
      if (isValid(i, currentRow, solution)) {
        if (currentRow + 1 == n) {
          result++;
          continue;
        }
        solution[currentRow] = i;
        solveNQueensRecursive(n, currentRow + 1, solution, result);
      }
    }
  }

  bool isValid(int attemptedColumn, int attemptedRow,
               std::vector<int> &queenInColumn) {

    for (int i = 0; i < attemptedRow; i++) {
      if (attemptedColumn == queenInColumn[i] ||
          abs(attemptedColumn - queenInColumn[i]) == abs(attemptedRow - i)) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
