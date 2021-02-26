//
// Created by xuqing01 on 2021/2/25.
//
/*
 * 21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。



示例 1：


输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：

输入：l1 = [], l2 = []
输出：[]
示例 3：

输入：l1 = [], l2 = [0]
输出：[0]


提示：

两个链表的节点数目范围是 [0, 50]
-100 <= Node.val <= 100
l1 和 l2 均按 非递减顺序 排列

 */
#include <iostream>
#include <unordered_map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//TODO recursion & better code
class Solution {
public:
    ///time O(n)
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        ListNode *newHead = nullptr;
        ListNode *cur = nullptr;
        while (l1 || l2) {
            if (l1 && l2) {
                ListNode *node = new ListNode(0, nullptr);
                if (l1->val < l2->val) {
                    node->val = l1->val;
                    l1 = l1->next;
                } else {
                    node->val = l2->val;
                    l2 = l2->next;
                }
                if (!cur) {
                    newHead = cur = node;
                } else {
                    cur->next = node;
                    cur = node;
                }
            } else {
                cur->next = l1 ? l1 : l2;
                break;
            }
        }

        return newHead;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution s;
    ListNode *l13 = new ListNode(4, nullptr);
    ListNode *l12 = new ListNode(2, l13);
    ListNode *l11 = new ListNode(1, l12);


    ListNode *l23 = new ListNode(4, nullptr);
    ListNode *l22 = new ListNode(3, l23);
    ListNode *l21 = new ListNode(1, l22);

    ListNode *result = s.mergeTwoLists(l11, l21);

    return 0;
}