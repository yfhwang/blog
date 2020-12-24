## [1. 两数之和](https://leetcode-cn.com/problems/two-sum/)

难度简单

### 题目描述

给定一个整数数组 `nums` 和一个目标值 `target`，请你在该数组中找出和为目标值的那 **两个** 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

**示例:**

```
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
```

### 分析

遍历所有的数

- 使用字典，如果字典的value中有当前节点的值，则输出
- 否则字典中加入节点[cur.index, target-cur.value]

### 解法一

brute force

遍历两遍所有的节点，时间复杂度$O({n^2})$

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if(nums[i]+nums[j]==target):
                    return [i, j]
        return []
```

### 解法二

使用一遍遍历，一边遍历一边将遍历过的数加入字典中。每遍历到一个新的数就先查阅字典，若字典中没有，则加入字典中；若字典中有，则遍历结束。

```python
#solution_2
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        if not nums:    #若nums为空则直接返回
            return []
        dict = {target-nums[0]: 0}  #设置字典
        for i in range(1, len(nums)):   #遍历所有数
            if(nums[i] in dict):
                return [dict[nums[i]], i]
            else:
                dict[target-nums[i]] = i
        return []
```

