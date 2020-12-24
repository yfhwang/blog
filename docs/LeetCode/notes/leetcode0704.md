## [704. 二分查找](https://leetcode-cn.com/problems/binary-search/)

### 题目描述

难度简单

给定一个 `n` 个元素有序的（升序）整型数组 `nums` 和一个目标值 `target` ，写一个函数搜索 `nums` 中的 `target`，如果目标值存在返回下标，否则返回 `-1`。


**示例 1:**

```
输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
```

**示例 2:**

```
输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
```



**提示：**

1. 你可以假设 `nums` 中的所有元素是不重复的。
2. `n` 将在 `[1, 10000]`之间。
3. `nums` 的每个元素都将在 `[-9999, 9999]`之间。

### 分析

题目分析

### 解法一

二分法套模板

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())    return -1;
        int l=0,r=nums.size()-1;
        while(l+1<r){
            int m = l + (r-l)/2;
            if(nums[m]>target)  r=m;
            else if(nums[m]<target)  l=m;
            else return m;
        }
        if(nums[l]==target) return l;
        if(nums[r]==target) return r;
        return -1;
    }
};
```

### 解法二

STL 不懂

```c++
// Author: Huahua
// Running time: 36 ms
class Solution {
public:
  int search(vector<int>& nums, int target) {
    auto it = lower_bound(nums.begin(), nums.end(), target);
    if (it == nums.end() || *it != target) return -1;
    return it - nums.begin();
  }
};
```

