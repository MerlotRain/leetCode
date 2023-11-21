/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 *
 * https://leetcode.com/problems/valid-number/description/
 *
 * algorithms
 * Hard (19.07%)
 * Likes:    1106
 * Dislikes: 1809
 * Total Accepted:    326.2K
 * Total Submissions: 1.7M
 * Testcase Example:  '"0"'
 *
 * A valid number can be split up into these components (in order):
 *
 *
 * A decimal number or an integer.
 * (Optional) An 'e' or 'E', followed by an integer.
 *
 *
 * A decimal number can be split up into these components (in order):
 *
 *
 * (Optional) A sign character (either '+' or '-').
 * One of the following formats:
 *
 * One or more digits, followed by a dot '.'.
 * One or more digits, followed by a dot '.', followed by one or more
 * digits.
 * A dot '.', followed by one or more digits.
 *
 *
 *
 *
 * An integer can be split up into these components (in order):
 *
 *
 * (Optional) A sign character (either '+' or '-').
 * One or more digits.
 *
 *
 * For example, all the following are valid numbers: ["2", "0089", "-0.1",
 * "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93",
 * "-123.456e789"], while the following are not valid numbers: ["abc", "1a",
 * "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].
 *
 * Given a string s, return true if s is a valid number.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "0"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "e"
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: s = "."
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 20
 * s consists of only English letters (both uppercase and lowercase), digits
 * (0-9), plus '+', minus '-', or dot '.'.
 *
 *
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
  bool isNumber(string s) {
    bool point = false;
    bool hasE = false;

    const char *str = s.c_str();
    while (isspace(*str)) {
      str++;
    }

    if (*str == '\0')
      return false;

    if (*str == '+' || *str == '-')
      str++;

    const char *head = str;
    for (; *str != '\0'; str++) {
      if (*str == '.') {
        if (point || hasE)
          return false;
        if (str == head && !isdigit(*(str + 1)))
          return false;
        point = true;
        continue;
      }

      if (*str == 'E' || *str == 'e') {
        if (hasE || s == head)
          return false;

        str++;

        if (*str == '+' || *str == '-')
          str++;
        if (!isdigit(*str))
          return false;

        hasE = true;
        continue;
      }

      if (isspace(*str)) {
        for (; *str != '\0'; str++) {
          if (!isspace(*str))
            return false;
        }
        return true;
      }
      if (!isdigit(*str)) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
