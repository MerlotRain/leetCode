/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Medium (27.98%)
 * Likes:    12089
 * Dislikes: 13101
 * Total Accepted:    2.9M
 * Total Submissions: 10.3M
 * Testcase Example:  '123'
 *
 * Given a signed 32-bit integer x, return x with its digits reversed. If
 * reversing x causes the value to go outside the signed 32-bit integer range
 * [-2^31, 2^31 - 1], then return 0.
 *
 * Assume the environment does not allow you to store 64-bit integers (signed
 * or unsigned).
 *
 *
 * Example 1:
 *
 *
 * Input: x = 123
 * Output: 321
 *
 *
 * Example 2:
 *
 *
 * Input: x = -123
 * Output: -321
 *
 *
 * Example 3:
 *
 *
 * Input: x = 120
 * Output: 21
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= x <= 2^31 - 1
 *
 *
 */

#include <stdint.h>
#include <stdio.h>
#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

// @lc code=start
class Solution {
public:
  // 123
  // 3
  // 12-> 2
  // 32
  // 1-> 1
  // 320 + 1
  int reverse(int x) {
    int y = 0;
    int n;
    while (x != 0) {
      n = x % 10;
      // Checking the over/underflow.
      // Actually, it should be y>(INT_MAX-n)/10, but n/10 is 0, so omit it.
      if (y > INT_MAX / 10 || y < INT_MIN / 10) {
        return 0;
      }
      y = y * 10 + n;
      x /= 10;
    }
    return y;
  }
};
// @lc code=end
