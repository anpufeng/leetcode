//
// Created by xuqing01 on 2021/2/4.
//


/*
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

 

示例 1:

输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
示例 4:

输入: s = ""
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }

//        return doubleLoop(s);
        return windowBorder(s);
    }

    //time O(n2) space O(n)
    int doubleLoop(string s) {
        int max = 0;
        int len = s.length();
        unordered_set<char> set;
        for (int i = 0; i < len; ++i) {
            set.clear();
            int loopMax = 1;
            char c = s.at(i);
            set.insert(c);
            for (int j = i + 1; j < len; ++j) {
                char laterC = s.at(j);
                auto it = set.find(laterC);
                if (it != set.end()) {
                    break;
                }
                set.insert(laterC);
                loopMax++;
            }
            if (loopMax > max) {
                max = loopMax;
            }
        }
        return max;
    }

    //time O(n) space O(n)
    int windowBorder(string s) {
        int max = 0, left = 0;
        int len = s.length();
        unordered_map<char, int> map;
        for (int right = 0; right < len; ++right) {
            auto it = map.find(s[right]);
            if (it == map.end() || (it != map.end() && it->second < left)) {
                max = std::max(max, right - left + 1);
            } else {
                left = map[s[right]] + 1;
            }
            map[s[right]]  = right;
        }
        return max;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution s;
    int max1 = s.lengthOfLongestSubstring("pwwkew");
    int max2 = s.lengthOfLongestSubstring("dvdf");
    int max3 = s.lengthOfLongestSubstring("abcdefghije");
    int max4 = s.lengthOfLongestSubstring("abcabcbb");
    int max5 = s.lengthOfLongestSubstring("tmmzuxt");

    return 0;
}