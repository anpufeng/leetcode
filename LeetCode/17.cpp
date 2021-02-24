//
// Created by xuqing01 on 2021/2/23.
//
/*
 * 17. 电话号码的字母组合
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



 

示例 1：

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
示例 2：

输入：digits = ""
输出：[]
示例 3：

输入：digits = "2"
输出：["a","b","c"]
 

提示：

0 <= digits.length <= 4
digits[i] 是范围 ['2', '9'] 的一个数字。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        unordered_map<char, string>digitMap = {
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"},
        };

        string combination;
        backtrack(combination, digitMap, result, 0, digits);

        return result;
    }

    void backtrack(string combination, unordered_map<char, string> &digitMap, vector<string> &result, int index, string &digits) {
        if (index == digits.length()) {
            result.push_back(combination);
        } else {
            string str = digitMap.at(digits[index]);
            for (int i = 0; i < str.length(); ++i) {
                combination.push_back(str[i]);
                backtrack(combination, digitMap, result, index+1, digits);
                combination.pop_back();
            }
        }
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution s;
    vector<string> result = s.letterCombinations("23");
//    vector<string> result = s.letterCombinations("2");

    return 0;
}

