/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (54.79%)
 * Likes:    11460
 * Dislikes: 2621
 * Total Accepted:    3.9M
 * Total Submissions: 7M
 * Testcase Example:  '121'
 *
 * Given an integer x, return true if x is a palindrome, and false
 * otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: x = 121
 * Output: true
 * Explanation: 121 reads as 121 from left to right and from right to left.
 *
 *
 * Example 2:
 *
 *
 * Input: x = -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 *
 *
 * Example 3:
 *
 *
 * Input: x = 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= x <= 2^31 - 1
 *
 *
 *
 * Follow up: Could you solve it without converting the integer to a string?
 */

// @lc code=start
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;

    // 121-2 121 % 100 = 21 / 10 = 2；
    //  12321 => 232: 12321 % 10000 = 2321 / 10 = 232;
    //  232
    //  1221=> 22 1221 % 1000 = 221 / 10 = 22;
    //  22 % 10 = 2 / 10 = 0
    int len = 1;
    for (; (x / len) >= 10; len *= 10)
      ;

      //121/1 >= 10 ? 10
      //121/10 >= 10 ? 100
      //121/100 >= 10 ? 100;



    while (x != 0) {
      int left = x / len; // 1
      int right = x % 10;
      if (left != right)
        return false;

      x = (x % len) / 10;
      len /= 100;
    }
    return true;
  }
};
// @lc code=end
