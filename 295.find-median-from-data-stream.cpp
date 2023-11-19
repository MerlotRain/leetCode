/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 *
 * https://leetcode.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (51.51%)
 * Likes:    11332
 * Dislikes: 223
 * Total Accepted:    702.7K
 * Total Submissions: 1.4M
 * Testcase Example:
 '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n' +
  '[[],[1],[2],[],[3],[]]'
 *
 * The median is the middle value in an ordered integer list. If the size of
 * the list is even, there is no middle value, and the median is the mean of
 * the two middle values.
 *
 *
 * For example, for arr = [2,3,4], the median is 3.
 * For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
 *
 *
 * Implement the MedianFinder class:
 *
 *
 * MedianFinder() initializes the MedianFinder object.
 * void addNum(int num) adds the integer num from the data stream to the data
 * structure.
 * double findMedian() returns the median of all elements so far. Answers
 * within 10^-5 of the actual answer will be accepted.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
 * [[], [1], [2], [], [3], []]
 * Output
 * [null, null, null, 1.5, null, 2.0]
 *
 * Explanation
 * MedianFinder medianFinder = new MedianFinder();
 * medianFinder.addNum(1);    // arr = [1]
 * medianFinder.addNum(2);    // arr = [1, 2]
 * medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
 * medianFinder.addNum(3);    // arr[1, 2, 3]
 * medianFinder.findMedian(); // return 2.0
 *
 *
 *
 * Constraints:
 *
 *
 * -10^5 <= num <= 10^5
 * There will be at least one element in the data structure before calling
 * findMedian.
 * At most 5 * 10^4 calls will be made to addNum and findMedian.
 *
 *
 *
 * Follow up:
 *
 *
 * If all integer numbers from the stream are in the range [0, 100], how would
 * you optimize your solution?
 * If 99% of all integer numbers from the stream are in the range [0, 100], how
 * would you optimize your solution?
 *
 *
 */

// @lc code=start
#include <queue>

class MedianFinder {
public:
  std::priority_queue<int> maxQueue;
  std::priority_queue<int, std::vector<int>, std::greater<int>> minQueue;

  MedianFinder() {}

  void addNum(int num) {
    // 大根堆为0，直接加入
    if (maxQueue.empty()) {
      maxQueue.push(num);
      return;
    }

    // 获取大根堆的头
    int top = maxQueue.top();
    if (num <= top) {
      maxQueue.push(num);
    } else {
      minQueue.push(num);
    }

    // 数据移动
    int minSize = minQueue.size();
    int maxSize = maxQueue.size();
    if (std::abs(minSize - maxSize) < 2) {
      return;
    }
    if (minSize > maxSize) {
      maxQueue.push(minQueue.top());
      minQueue.pop();
    } else if (minSize < maxSize) {
      minQueue.push(maxQueue.top());
      maxQueue.pop();
    }
  }

  double findMedian() {
    int minSize = minQueue.size();
    int maxSize = maxQueue.size();
    if (minSize == 0 && maxSize == 0) {
      return 0.0;
    }
    if (minSize == maxSize) {
      return (minQueue.top() + maxQueue.top()) / 2.0;
    } else {
      double a = minQueue.size() > 0 ? minQueue.top() : 0.0;
      double b = maxQueue.size() > 0 ? maxQueue.top() : 0.0;
      return (a + b) / 2.0;
    }
    return 0.0;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
