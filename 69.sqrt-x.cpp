/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (38.10%)
 * Likes:    7565
 * Dislikes: 4367
 * Total Accepted:    1.7M
 * Total Submissions: 4.5M
 * Testcase Example:  '4'
 *
 * Given a non-negative integer x, return the square root of x rounded down to
 * the nearest integer. The returned integer should be non-negative as well.
 *
 * You must not use any built-in exponent function or operator.
 *
 *
 * For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: x = 4
 * Output: 2
 * Explanation: The square root of 4 is 2, so we return 2.
 *
 *
 * Example 2:
 *
 *
 * Input: x = 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since we round it down
 * to the nearest integer, 2 is returned.
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= x <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:
  int mySqrt(int x) {

    if (x <= 0)
      return 0;

    // the sqrt is not greater than x/2+1
    int e = x / 2 + 1;
    int s = 0;
    // binary search
    while (s <= e) {
      int mid = s + (e - s) / 2;
      long long sq = (long long)mid * (long long)mid;
      if (sq == x)
        return mid;
      if (sq < x) {
        s = mid + 1;
      } else {
        e = mid - 1;
      }
    }
    return e;
  }
};
// @lc code=end
