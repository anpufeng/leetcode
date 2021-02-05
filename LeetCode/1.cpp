//
// Created by xuqing01 on 2021/2/3.
//

/*
 * 1. 两数之和
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

你可以按任意顺序返回答案。

 

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

struct NumNode {
    int value;
    int index;
    NumNode(int v, int i) : value(v), index(i) {}
};

bool compareNumIndex(NumNode i1, NumNode i2) {
    return (i1.value < i2.value);
}

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() <= 1) {
            return vector<int> {0};
        }

//        return doubleLoop(nums, target);
        return sortAndSearch(nums, target);
        return hashMap(nums, target);

    }
    //time: O(n2) space: O(1)
    vector<int> doubleLoop(vector<int>& nums, int target) {
        int size = nums.size();
        for (int i = 0 ; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
               if (nums[i] + nums[j] == target) {
                   return vector<int>{i, j};
               }
            }
        }
        return vector<int> {0};
    }


    //time: copy O(n) sort O(nlogn) space: O(n)
    vector<int> sortAndSearch(vector<int>& nums, int target) {
        int size = nums.size();
        vector<struct NumNode> numNodeList;
        for (int i = 0; i < size; i++) {
            NumNode n(nums[i], i);
            numNodeList.push_back(n);
        }
        sort(numNodeList.begin(), numNodeList.end(), compareNumIndex);
        for (int i = 0, j = size -1; i < size && i != j;) {
            int sum = numNodeList[i].value + numNodeList[j].value;
            if (sum > target) {
               j--;
            } else if (sum == target) {
                return vector<int>{numNodeList[i].index, numNodeList[j].index};
            } else {
                i++;
            }
        }
        return vector<int> {0};
    }

    //time O(n), space O(n);
    vector<int> hashMap(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int, int> map;
        for (int i = 0; i < size; ++i) {
            auto iter = map.find(target-nums[i]);
            if (iter != map.end()) {
                return vector<int>(iter->second, i);
            }
            map[nums[i]] = i;
        }
        return vector<int> {0};
        /*
         bad code

        int size = nums.size();
        map<int, vector<NumNode>> numMap;
        for (int i = 0; i < size; i++) {
            NumNode n{};
            n.index = i;
            n.value = nums[i];
            auto iter = numMap.find( nums[i]);
            if (iter == numMap.end()) {
                vector<NumNode> nodes = vector<NumNode>{n};
                numMap[nums[i]] = nodes;
            } else {
                iter->second.push_back(n);
            }
        }
        for (int i = 0; i < size; i++) {
            auto iter = numMap.find(target - nums[i]);
            if (iter == numMap.end()) {
                continue;
            }
            for (auto node : iter->second) {
                if (node.index == i) {
                    continue;
                }
                return vector<int>{i, node.index};
            }
        }
        return vector<int>{};
          */
    }


    void printVector(vector<int> &nums) {
        for (auto num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> arr1 = vector<int>{2,7,11,15, 3};
    vector<int> arr2 = vector<int>{3,2,4};
    vector<int> arr3 = vector<int>{3,3};

    Solution s;
    vector<int> r1 = s.twoSum(arr1, 9);
    vector<int> r2 = s.twoSum(arr2, 6);
    vector<int> r3 = s.twoSum(arr3, 6);

    s.printVector(r1);
    s.printVector(r2);
    s.printVector(r3);
    return 0;
}
