## [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

### 题目描述

难度中等

给定一个按照升序排列的整数数组 `nums`，和一个目标值 `target`。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 *O*(log *n*) 级别。

如果数组中不存在目标值，返回 `[-1, -1]`。

**示例 1:**

```
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
```

**示例 2:**

```
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
```

### 分析

- 做两次二分查找，一次找左边界，一次找右边界

- 重点：[mid]=target时，

  如果目标是左边界，则移动右指针

  如果目标是右边界，则移动左指针

### 解法一

- 根据篮子王的代码模板修改
- `l+1<r`用以避免死循环的情况

```c++
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.empty())	return {-1,-1};
    return {firstPos(nums, target), lastPos(nums, target)};
  }
private:
  //找左边界的函数
  int firstPos(const vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size()-1;
    while (l+1 < r) {
      int m = l + (r - l) / 2;
      //[mid]=target时，移动右指针
      if (nums[m] >= target)	r = m;
			else	l = m;
    }
    if(nums[l]==target)	return l;
    else if(nums[r]==target)	return r;
    else return -1;
  }
  
  //找右边界的函数
  int lastPos(const vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size()-1;
    while (l+1 < r) {
      int m = l + (r - l) / 2;      
      //[mid]=target时，移动左指针
      if (nums[m] > target)	r = m;
      else	l = m;
    }
    if(nums[r]==target)	return r;
    else if(nums[l]==target)	return l;
    else return -1;
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
  vector<int> searchRange(vector<int>& nums, int target) {
    return {firstPos(nums, target), lastPos(nums, target)};
  }
private:
  //找左边界的函数
  int firstPos(const vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size();
    while (l < r) {
      int m = l + (r - l) / 2;
      //[mid]=target时，移动右指针
      if (nums[m] >= target) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    //左边界到了最右，仍未找到；或找不到target，如[1,3,5,7]中查找 4
    if (l == nums.size() || nums[l] != target) return -1;
    return l;    
  }
  //找右边界的函数
  int lastPos(const vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size();
    while (l < r) {
      int m = l + (r - l) / 2;      
      if (nums[m] > target) {
        r = m;
      } else {	//[mid]=target时，移动左指针
        l = m + 1;
      }
    }
    --l;	//nums[m] == target 时的最后一步为l=m+1,实际应为l=m        
    if (l < 0 || nums[l] != target) return -1;
    return l;
  }
};
```

