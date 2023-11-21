/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (44.72%)
 * Likes:    15132
 * Dislikes: 658
 * Total Accepted:    2.5M
 * Total Submissions: 5.6M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array of distinct integers and a target value, return the
 * index if the target is found. If not, return the index where it would be if
 * it were inserted in order.
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,3,5,6], target = 5
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,3,5,6], target = 2
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,3,5,6], target = 7
 * Output: 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums contains distinct values sorted in ascending order.
 * -10^4 <= target <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
  int binary_search(std::vector<int> &A, int key) {
    int low = 0;
    int high = A.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (A[mid] == key) {
        return mid;
      }
      if (key > A[mid]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return low;
  }

  int searchInsert(vector<int> &nums, int target) {

    if (nums.size() == 0)
      return 0;

    return binary_search(nums, target);
  }
};

/**
 * @brief 简历面试
 *
 * 外包性质：西安有1000多人，荣耀有300人，PC30人左右
 * Windows下的exe开发
 * VS2017下的C++
 * 界面Win32的套路，MFC的套路
 * DUIlib
 *
 *
 */
// @lc code=end
