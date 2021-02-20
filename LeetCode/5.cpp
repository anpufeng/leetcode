//
// Created by xuqing01 on 2021/2/8.
//
/*
 * palindromic
 * 5. 最长回文子串
 * 给你一个字符串 s，找到 s 中最长的回文子串。

 

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"
示例 3：

输入：s = "a"
输出："a"
示例 4：

输入：s = "ac"
输出："a"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int max = 0;
        int left, right;
        for (int i = 0; i < len; ++i) {
            for (int j = i; j < len; ++j) {
               if (j - i + 1 > max && isPalindrome(s, i, j)) {
                   max = j - i + 1;
                   left = i;
                   right = j;
               }
            }
        }

        return s.substr(left, right - left + 1);
    }


    bool isPalindrome(string& s, int left, int right) {
        int len = right - left + 1;
        if (len == 1) {
            return true;
        }
        while (left <= right) {
            if (s[left++] == s[right--]) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution s;

    string p1 = s.longestPalindrome("babad");
    string p2 = s.longestPalindrome("cbbd");
    string p3 = s.longestPalindrome("a");
    string p4 = s.longestPalindrome("ac");
    string p5 = s.longestPalindrome("bb");
    string p6 = s.longestPalindrome("iopsajhffgvrnyitusobwcxgwlwniqchfnssqttdrnqqcsrigjsxkzcmuoiyxzerakhmexuyeuhjfobrmkoqdljrlojjjysfdslyvckxhuleagmxnzvikfitmkfhevfesnwltekstsueefbrddxrmxokpaxsenwlgytdaexgfwtneurhxvjvpsliepgvspdchmhggybwupiqaqlhjjrildjuewkdxbcpsbjtsevkppvgilrlspejqvzpfeorjmrbdppovvpzxcytscycgwsbnmspihzldjdgilnrlmhaswqaqbecmaocesnpqaotamwofyyfsbmxidowusogmylhlhxftnrmhtnnljjhhcfvywsqimqxqobfsageysonuoagmmviozeouutsiecitrmkypwknorjjiaasxfhsftypspwhvqovmwkjuehujofiabznpipidhfxpoustquzyfurkcgmioxacleqdxgrxbldcuxzgbcazgfismcgmgtjuwchymkzoiqhzaqrtiykdkydgvuaqkllbsactntexcybbjaxlfhyvbxieelstduqzfkoceqzgncvexklahxjnvtyqcjtbfanzgpdmucjlqpiolklmjxnscjcyiybdkgitxnuvtmoypcdldrvalxcxalpwumfx");

    assert(p1 == "bab" || p1 == "aba");
    assert(p2 == "bb");
    assert(p3 == "a");
    assert(p4 == "a");
    assert(p5 == "bb");

    return 0;
}

