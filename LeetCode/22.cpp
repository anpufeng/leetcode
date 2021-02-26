//
// Created by xuqing01 on 2021/2/25.
//

#include <iostream>
#include <unordered_map>
#include <set>
#include <stack>
#include <vector>

/*
 * 22. 括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。



示例 1：

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：

输入：n = 1
输出：["()"]


提示：

1 <= n <= 8

 */
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return bruteForce(n);
    }

    ///time O(n * 2^2n) space O(n)
    vector<string> bruteForce(int n) {
        vector<string> allList;
        string combination;
        backtrack(allList, combination, n * 2);
        return allList;
    }

    void backtrack(vector<string> &result, string &combination, int n) {
        if (n == 0) {
            if (isValid(combination)) {
                result.push_back(combination);
            }
            return;
        }
        string paris = "()";
        for (int i = 0; i < paris.length(); ++i) {
            combination.push_back(paris[i]);
            backtrack(result, combination, n-1);
            combination.pop_back();
        }
    }
    bool isValid(string s) {
        if (!s.length() || s[0] == ')') {
            return false;
        }

        stack<char> stack;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (!stack.empty()) {
                if (c == ')') {
                    char top = stack.top();
                    top == '(' ?  stack.pop() : stack.push(c);
                } else {
                    stack.push(c);
                }
            } else {
                if (c == ')') {
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
    s.generateParenthesis(3);
    return 0;
}