/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 *
 * https://leetcode.com/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (49.01%)
 * Likes:    14415
 * Dislikes: 1197
 * Total Accepted:    2.5M
 * Total Submissions: 5M
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * Given head, the head of a linked list, determine if the linked list has a
 * cycle in it.
 *
 * There is a cycle in a linked list if there is some node in the list that can
 * be reached again by continuously following the next pointer. Internally, pos
 * is used to denote the index of the node that tail's next pointer is
 * connected to. Note that pos is not passed as a parameter.
 *
 * Return true if there is a cycle in the linked list. Otherwise, return
 * false.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [3,2,0,-4], pos = 1
 * Output: true
 * Explanation: There is a cycle in the linked list, where the tail connects to
 * the 1st node (0-indexed).
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2], pos = 0
 * Output: true
 * Explanation: There is a cycle in the linked list, where the tail connects to
 * the 0th node.
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1], pos = -1
 * Output: false
 * Explanation: There is no cycle in the linked list.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of the nodes in the list is in the range [0, 10^4].
 * -10^5 <= Node.val <= 10^5
 * pos is -1 or a valid index in the linked-list.
 *
 *
 *
 * Follow up: Can you solve it using O(1) (i.e. constant) memory?
 *
 */

// @lc code=start

#include <stdlib.h>

// Definition for singly-linked list.
/*
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
*/

/**
 * @brief 单链表的核心问题在于，一定要清楚，一个node一定是只有一个next桌子很
 * 所以绝对不会出现 'x' 形相交的情况，因为这样一定是某节点有两个next指针
 * 
 */

class Solution {
public:
  bool hasCycle(ListNode *head) {
    // 无节点，一个节点，或两个节点，都不会形成环
    if (!head || !head->next || !head->next->next)
      return false;

    // 快慢指针
    ListNode *fast = head->next->next;
    ListNode *slow = head->next;

    // 如果有环，快指针和慢指针总会有相遇的时候
    while (fast != slow) {
      if (fast->next == NULL || fast->next->next == NULL)
        return false;
      fast = fast->next->next;
      slow = slow->next;
    }
    return true;
    // 说明存在环
  }
};
// @lc code=end
