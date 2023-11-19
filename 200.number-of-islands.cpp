/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (58.04%)
 * Likes:    21556
 * Dislikes: 468
 * Total Accepted:    2.4M
 * Total Submissions: 4.1M
 * Testcase Example:
 * '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and
 * '0's (water), return the number of islands.
 *
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are
 * all surrounded by water.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] is '0' or '1'.
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
  void mask(vector<vector<char>> &grid, int row, int column) {
    if (row < 0 || row >= grid.size() || column < 0 ||
        column >= grid[row].size() || grid[row][column] != '1')
      return;

    grid[row][column] = '2';
    mask(grid, row + 1, column);
    mask(grid, row - 1, column);
    mask(grid, row, column + 1);
    mask(grid, row, column - 1);
  }

  int numIslands(vector<vector<char>> &grid) {
    int result = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == '1') {
          result++;
          mask(grid, i, j);
        }
      }
    }
    return result;
  }
};
// @lc code=end
