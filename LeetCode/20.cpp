//
// Created by xuqing01 on 2021/2/24.
//
/*
 * 20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。


示例 1：

输入：s = "()"
输出：true
示例 2：

输入：s = "()[]{}"
输出：true
示例 3：

输入：s = "(]"
输出：false
示例 4：

输入：s = "([)]"
输出：false
示例 5：

输入：s = "{[]}"
输出：true


提示：

1 <= s.length <= 104
s 仅由括号 '()[]{}' 组成
 */
#include <iostream>
#include <unordered_map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (!s.length()) {
            return false;
        }
        unordered_map<char, char>pair = {
                {')', '('},
                {']', '['},
                {'}', '{'},
        };

        stack<char> stack;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (!stack.empty()) {
                char top = stack.top();
                auto iterator = pair.find(c);
                if (iterator != pair.end() && iterator->second == top) {
                    stack.pop();
                } else {
                    stack.push(c);
                }
            } else {
                if (c == ')' || c == ']' || c == '}') {
                    return false;
                } else {
                    stack.push(c);
                }
            }
        }
        return stack.empty();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution s;

    return 0;
}