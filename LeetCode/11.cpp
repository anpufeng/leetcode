//
// Created by xuqing01 on 2021/2/20.
//
/*
 * 11. 盛最多水的容器
 * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器。

 

示例 1：

https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg

输入：[1,8,6,2,5,4,8,3,7]
输出：49
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
示例 2：

输入：height = [1,1]
输出：1
示例 3：

输入：height = [4,3,2,1,4]
输出：16
示例 4：

输入：height = [1,2,1]
输出：2
 

提示：

n = height.length
2 <= n <= 3 * 104
0 <= height[i] <= 3 * 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
//        return bruteForce(height);
        return towPointers(height);
    }

    ///time O(n^2) space O(1) , timout
    int bruteForce(vector<int> &height) {
        size_t  size = height.size();
        int result = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                result = max(result, (j - i) * min(height[i], height[j]));
            }
        }
        return result;
    }

    int towPointers(vector<int> &height) {
        int result = 0, left = 0, right = height.size() -1;
        while (left < right) {
            result = max(result, (right - left) * min(height[right], height[left]));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return result;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution s;

    return 0;
}