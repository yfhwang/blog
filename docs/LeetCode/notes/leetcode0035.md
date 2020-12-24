## [35. 搜索插入位置](https://leetcode-cn.com/problems/search-insert-position/)

### 题目描述

难度简单

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

**示例 1:**

```
输入: [1,3,5,6], 5
输出: 2
```

**示例 2:**

```
输入: [1,3,5,6], 2
输出: 1
```

**示例 3:**

```
输入: [1,3,5,6], 7
输出: 4
```

**示例 4:**

```
输入: [1,3,5,6], 0
输出: 0
```

### 分析

![屏幕快照 2020-02-24 15.23.42 (2)-2529057](../images/屏幕快照 2020-02-24 15.23.42 (2)-2529057.png)

### 解法一

使用二分法模版，避免死循环

- `int m = l + (r - l) / 2;`避免溢出

- 当左右指针相遇时停止循环，相遇的两个值还没被检测过，要根据不同题意来检测

- 二次检查的部分：

  若target比r大，则放到r右边的位置
  若target比l小，则放到l的位置

```c++
class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int l = 0, r = nums.size() - 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (target < nums[m])
                r = m;
            else if (nums[m] < target)
                l = m;
            else
                return m;
        }
        if (target <= nums[l]) return l;
        else if (target > nums[r]) return r + 1;
        else return r;
    }
};
```

### 解法二

Time complexity: O(logn)
Space complexity: O(1)

```c++
// Author: Huahua
class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
      int m = l + (r - l) / 2;      
      if (nums[m] == target)
        return m;
      else if (nums[m] > target)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};
```

