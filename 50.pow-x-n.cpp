/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (34.14%)
 * Likes:    8995
 * Dislikes: 8851
 * Total Accepted:    1.4M
 * Total Submissions: 4.2M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (i.e.,
 * x^n).
 *
 *
 * Example 1:
 *
 *
 * Input: x = 2.00000, n = 10
 * Output: 1024.00000
 *
 *
 * Example 2:
 *
 *
 * Input: x = 2.10000, n = 3
 * Output: 9.26100
 *
 *
 * Example 3:
 *
 *
 * Input: x = 2.00000, n = -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 *
 *
 *
 * Constraints:
 *
 *
 * -100.0 < x < 100.0
 * -2^31 <= n <= 2^31-1
 * n is an integer.
 * Either x is not zero or n > 0.
 * -10^4 <= x^n <= 10^4
 *
 *
 */

#include <iostream>
#define INT_MAX 2147483647
#define INT_MIN -2147483648

// @lc code=start
class Solution {
public:
  // 2, -2 = 1/ 4;
  double myPow(double x, int n) {
    if (x == 1.0 || x == -1.0)
      return 1.0;

    bool sign = false;
    long long rep = n;
    if (n < 0) {
      sign = true;
      rep = -rep;
    } else {
      rep = rep;
    }

    double result = 1.0;
    for (long long i = 0; i < rep; i++) {
      result *= x;
    }

    return sign ? 1 / result : result;
  }
};
// @lc code=end
