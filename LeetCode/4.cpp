//
// Created by xuqing01 on 2021/2/5.
//

/*
 *
 * 4. 寻找两个正序数组的中位数
 * 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。

进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？

 

示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
示例 3：

输入：nums1 = [0,0], nums2 = [0,0]
输出：0.00000
示例 4：

输入：nums1 = [], nums2 = [1]
输出：1.00000
示例 5：

输入：nums1 = [2], nums2 = []
输出：2.00000
 

提示：

nums1.length == m
        nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        if (size1 == 0) {
            return medianOfSortedArray(nums2);
        }
        if (size2 == 0) {
            return medianOfSortedArray(nums1);
        }

        int size = max(size1, size2);
        vector<int> num;
        int i = 0, j = 0;
        while (i < size || j < size) {
            if (i < size1 && j < size2) {
                int n1 = nums1[i];
                int n2 = nums2[j];
                if (n1 >= n2) {
                    j++;
                    num.push_back(n2);
                } else {
                    i++;
                    num.push_back(n1);
                }
            } else if (i >= size1 && j < size2) {
                num.push_back(nums2[j]);
                j++;
            } else if (i < size1 && j >= size2) {
                num.push_back(nums1[i]);
                i++;
            } else {
                break;
            }
        }
        return medianOfSortedArray(num);
    }
    double medianOfSortedArray(vector<int> &num) {
        int size = num.size();
        if (size == 0) {
            return 0;
        }
        if (size % 2 == 0) {
            return (num[(size-1)/2] + num[size/2])/2.0f;
        } else {
            return num[(size-1) / 2];
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> num1 = {0,0,0,0,0};
    vector<int> num2 = {-1,0,0,0,0,0,1};
    Solution s;
    s.findMedianSortedArrays(num1, num2);

    return 0;
}