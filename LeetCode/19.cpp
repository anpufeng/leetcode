//
// Created by xuqing01 on 2021/2/24.
//
/*
 * 19. 删除链表的倒数第 N 个结点
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

进阶：你能尝试使用一趟扫描实现吗？

 

示例 1：


输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
示例 2：

输入：head = [1], n = 1
输出：[]
示例 3：

输入：head = [1,2], n = 1
输出：[1]
 

提示：

链表中结点的数目为 sz
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int index = 0;
        unordered_map<int, ListNode *>map;
        while (head) {
            map[index] = head;
            head = head->next;
            index++;
        }
        if (map.size() <= 1) {
            return nullptr;
        }
        int removeIndex = map.size() - n;
        if (removeIndex == 0) {
            return map.at(1);
        } else {
            map.at(removeIndex-1)->next = removeIndex == map.size() - 1 ? nullptr : map.at(removeIndex+1);
            return map.at(0);
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution s;

    return 0;
}

