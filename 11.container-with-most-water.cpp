/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (54.30%)
 * Likes:    27248
 * Dislikes: 1507
 * Total Accepted:    2.5M
 * Total Submissions: 4.6M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * You are given an integer array height of length n. There are n vertical
 * lines drawn such that the two endpoints of the i^th line are (i, 0) and (i,
 * height[i]).
 *
 * Find two lines that together with the x-axis form a container, such that the
 * container contains the most water.
 *
 * Return the maximum amount of water a container can store.
 *
 * Notice that you may not slant the container.
 *
 *
 * Example 1:
 *
 *
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * Explanation: The above vertical lines are represented by array
 * [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
 * container can contain is 49.
 *
 *
 * Example 2:
 *
 *
 * Input: height = [1,1]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * n == height.length
 * 2 <= n <= 10^5
 * 0 <= height[i] <= 10^4
 *
 *
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int maxArea(vector<int> &height) {

    int maxArea = 0;
    // two pointers scan from two sides to middle
    int left = 0;
    int right = height.size() - 1;

    int area;
    while (left < right) {
      // calculate the area
      area = (right - left) *
             (height[left] < height[right] ? height[left] : height[right]);
      // tracking the maxium area
      maxArea = area > maxArea ? area : maxArea;
      // because the area is decided by the shorter edge
      // so we increase the area is to increase the shorter edge
      //
      //     height[left] < height[right] ? left++ : right-- ;
      //
      // However, the above code could cause the unnecessary `area` cacluation
      // We can do some improvement as below:
      if (height[left] < height[right]) {
        do {
          left++;
        } while (left < right && height[left - 1] >= height[left]);
      } else {
        do {
          right--;
        } while (right > left && height[right + 1] >= height[right]);
      }
    }

    return maxArea;
  }
};
// @lc code=end
