/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (52.85%)
 * Likes:    8940
 * Dislikes: 897
 * Total Accepted:    1.3M
 * Total Submissions: 2.5M
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings a and b, return their sum as a binary string.
 *
 *
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 *
 * Constraints:
 *
 *
 * 1 <= a.length, b.length <= 10^4
 * a and b consist only of '0' or '1' characters.
 * Each string does not contain leading zeros except for the zero itself.
 *
 *
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    int alen = a.size();
    int blen = b.size();
    bool carry = false;
    string result;
    while (alen > 0 || blen > 0) {
      int abit = alen <= 0 ? 0 : a[alen - 1] - '0';
      int bbit = blen <= 0 ? 0 : b[blen - 1] - '0';
      int cbit = carry ? 1 : 0;
      result.insert(result.begin(), '0' + ((abit + bbit + cbit) & 1));
      carry = (abit + bbit + cbit > 1);
      alen--;
      blen--;
    }
    if (carry) {
      result.insert(result.begin(), '1');
    }
    return result;
  }
};
// @lc code=end
