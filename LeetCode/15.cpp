//
// Created by xuqing01 on 2021/2/22.
//
/*
15. 三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。



示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
示例 2：

输入：nums = []
输出：[]
示例 3：

输入：nums = [0]
输出：[]


提示：

0 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/
#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return{};
        }

        return sortAndLoop(nums);
        ///remove same nums
        unordered_map<int, int>map;
        vector<int> list;
        for (int i = 0; i < nums.size(); ++i) {
            auto iterator = map.find(nums[i]);
            if (iterator != map.end()) {
                int count = iterator->second;
                if (count < 3) {
                    map[nums[i]] = count+1;
                    list.push_back(nums[i]);
                }
            } else {
                map[nums[i]] = 1;
                list.push_back(nums[i]);
            }
        }
        return sortAndLoop(list);
    }

    vector<vector<int>> sortAndLoop(vector<int>& nums) {
        vector<vector<int>> result;
        set<string> set;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; ++i) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int minus = -nums[i];
            int left = i + 1, right = size - 1;
            while (left < right) {
                if (left > i + 1 && nums[left] == nums[left-1]) {
                    left++;
                    continue;
                }
                int sum = nums[left] + nums[right];
                if (sum > minus) {
                    right--;
                } else if (sum < minus) {
                    left++;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution s;

    vector<int> nums =  {-1,0,1,2,-1,-4};
    vector<vector<int>> result = s.threeSum(nums);
//    vector<int> nums =  {1, 1, -2};
//    vector<vector<int>> result = s.threeSum(nums);

    return 0;
}