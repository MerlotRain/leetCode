/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (50.24%)
 * Likes:    12898
 * Dislikes: 896
 * Total Accepted:    1.2M
 * Total Submissions: 2.3M
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * Given the head of a linked list, return the node where the cycle begins. If
 * there is no cycle, return null.
 *
 * There is a cycle in a linked list if there is some node in the list that can
 * be reached again by continuously following the next pointer. Internally, pos
 * is used to denote the index of the node that tail's next pointer is
 * connected to (0-indexed). It is -1 if there is no cycle. Note that pos is
 * not passed as a parameter.
 *
 * Do not modify the linked list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [3,2,0,-4], pos = 1
 * Output: tail connects to node index 1
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * second node.
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2], pos = 0
 * Output: tail connects to node index 0
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * first node.
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1], pos = -1
 * Output: no cycle
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
#include <math.h>
#include <stdlib.h>

// Definition for singly-linked list.

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL)
      return NULL;

    ListNode *fast = head->next->next;
    ListNode *slow = head->next;

    while (fast != slow) {
      if (fast->next == NULL || fast->next->next == NULL)
        return NULL;
      fast = fast->next->next;
      slow = slow->next;
    }

    // 指针相遇，快指针重置
    fast = head;

    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }
    return fast;
  }
};
// @lc code=end

// 两个无环或者有环的单链表，如果两个链表相交，求第一个相交的节点

/**
 * 1、判断是否是环形链表
 */
ListNode *detectCycle(ListNode *head) {
  if (head == NULL || head->next == NULL || head->next->next == NULL)
    return NULL;

  ListNode *fast = head->next->next;
  ListNode *slow = head->next;

  while (fast != slow) {
    if (fast->next == NULL || fast->next->next == NULL)
      return NULL;
    fast = fast->next->next;
    slow = slow->next;
  }

  // 指针相遇，快指针重置
  fast = head;

  while (fast != slow) {
    fast = fast->next;
    slow = slow->next;
  }
  return fast;
}

ListNode *noLoop(ListNode *head1, ListNode *head2, ListNode *end1 = NULL,
                 ListNode *end2 = NULL) {
  if (head1 == NULL || head2 == NULL)
    return NULL;

  ListNode *cur1 = head1;
  ListNode *cur2 = head2;
  int n = 0;
  while (cur1->next != end1) {
    n++;
    cur1 = cur1->next;
  }

  while (cur2->next != end2) {
    n--;
    cur2 = cur2->next;
  }
  if (cur1 != cur2)
    return NULL;

  cur1 = (n > 0) ? head1 : head2;
  cur2 = cur1 == head1 ? head2 : head2;
  n = fabs(n);
  while (n != 0) {
    n--;
    cur1 = cur1->next;
  }

  while (cur1 != cur2) {
    cur1 = cur1->next;
    cur2 = cur2->next;
  }
  return cur1;
}

ListNode *bothLoop(ListNode *head1, ListNode *loop1, ListNode *head2,
                   ListNode *loop2) {
  if (loop1 == loop2) {
    // 此时的两个环是一样的，可能存在环之前的部分相交，所以将
    // loop节点作为end输入无环链表中查询
    return noLoop(head1, head2, loop1, loop2);
  } else {
    // 此时，一个loop去遍历这个环，如果找到了第二个loop，则返回两个loop的其中之一
    // 如果找完都没有找到，说明两个环链表是不相交的
    ListNode *cur1 = loop1->next;
    while (cur1 != loop1) {
      if (cur1 == loop2) {
        return loop1;
      }
      cur1 = cur1->next;
    }
    return NULL;
  }
}

ListNode *twoListNodeFirstIntersctionNode(ListNode *head1, ListNode *head2) {
  ListNode *loop1 = detectCycle(head1);
  ListNode *loop2 = detectCycle(head2);
  // 两个无环链表的相交问题
  if (!loop1 && !loop2) {
    return noLoop(head1, head2);
  }
  // 两个有环链表的相交问题
  if (loop1 && loop2) {
    return bothLoop(head1, loop1, head2, loop2);
  }

  // 一个有环，一个无环，绝对不可能相交
  return NULL;
}