/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (46.30%)
 * Likes:    6937
 * Dislikes: 13633
 * Total Accepted:    1.2M
 * Total Submissions: 2.5M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 *
 *
 * string convert(string s, int numRows);
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 *
 * Example 3:
 *
 *
 * Input: s = "A", numRows = 1
 * Output: "A"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consists of English letters (lower-case and upper-case), ',' and '.'.
 * 1 <= numRows <= 1000
 *
 *
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
  string convert(string s, int numRows) {

    if (numRows <= 1 || numRows >= s.size())
      return s;
    std::vector<std::string> r(numRows);

    // 0,1,2...numRows-1,numRows-2...0,1,...
    int row = 0;
    int step = 1;
    for (int i = 0; i < s.size(); i++) {
      if (row == numRows - 1)
        step = -1;
      if (row == 0)
        step = 1;
      r[row] += s[i];
      row += step;
    }

    std::string result;
    for (int i = 0; i < numRows; i++) {
      result += r.at(i);
    }
    return result;
  }
};
// @lc code=end
