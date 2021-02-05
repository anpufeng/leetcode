//
// Created by xuqing01 on 2021/2/4.
//

/*
 * 2. 两数相加
 *
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

 

示例 1：


输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
示例 2：

输入：l1 = [0], l2 = [0]
输出：[0]
示例 3：

输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    //time O(max(m,n))      space O(max(m,n))
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int sum = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            if (sum > 9) {
                carry = 1;
                sum = sum % 10;
            } else {
                carry = 0;
            }
            ListNode *node = new ListNode(sum);
            if (!head) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }
        if (carry == 1) {
            ListNode *node = new ListNode(carry);
            tail->next = node;
        }
        return head;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    ListNode *l1 = new ListNode(2, nullptr);
    ListNode *l2 = new ListNode(4, nullptr);
    ListNode *l3 = new ListNode(3, nullptr);
    l1->next = l2;
    l2->next = l3;

    ListNode *l4 = new ListNode(5, nullptr);
    ListNode *l5 = new ListNode(6, nullptr);
    ListNode *l6 = new ListNode(4, nullptr);
    l4->next = l5;
    l5->next = l6;

    Solution s;
    s.addTwoNumbers(l1, l4);

    return 0;
}
