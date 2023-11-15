/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (71.83%)
 * Likes:    15566
 * Dislikes: 638
 * Total Accepted:    2.5M
 * Total Submissions: 3.4M
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers nums, every element appears twice except
 * for one. Find that single one.
 *
 * You must implement a solution with a linear runtime complexity and use only
 * constant extra space.
 *
 *
 * Example 1:
 * Input: nums = [2,2,1]
 * Output: 1
 * Example 2:
 * Input: nums = [4,1,2,1,2]
 * Output: 4
 * Example 3:
 * Input: nums = [1]
 * Output: 1
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * -3 * 10^4 <= nums[i] <= 3 * 10^4
 * Each element in the array appears twice except for one element which appears
 * only once.
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    if (nums.size() < 0)
      return 0;

    int eor = 0;
    for (auto &cur : nums)
      eor ^= cur;

    return eor;
  }

  int doubleNumber(vector<int> &nums) {
    if (nums.size() < 0)
      return 0;

    int eor = 0;
    for (auto &cur : nums)
      eor ^= cur;

    /**
     * @brief
     * eor:    1 0 0 1 0 0 1 1
     * ~eor:   0 1 1 0 1 1 0 0
     * ~eor+1: 0 1 1 0 1 1 0 1
     * &       0 0 0 0 0 0 0 1
     */
    // 取出一个数字中最右侧的1，其他高位都是0
    int rightOne = eor & (~eor + 1);
    int onlyone = 0;
    for (auto &cur : nums) {
      if ((cur & rightOne) == 1) {
        onlyone ^= cur;
      }
    }

    std::cout << onlyone << " " << (eor ^ onlyone) << std::endl;
  }

  //1，2，1，3，4，2，3，5，1
};
// @lc code=end
