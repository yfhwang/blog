## [33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)

### 题目描述

难度中等

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 `[0,1,2,4,5,6,7]` 可能变为 `[4,5,6,7,0,1,2]` )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 `-1` 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 *O*(log *n*) 级别。

**示例 1:**

```
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
```

**示例 2:**

```
输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
```

### 分析

分类讨论

![屏幕快照 2020-02-24 17.14.59 (2)](../images/屏幕快照 2020-02-24 17.14.59 (2).png)

### 解法一

解法一说明

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())    return -1;
        int l=0,r=nums.size()-1;
        while(l+1<r){
            int m = l + (r-l)/2;
            if(nums[m]==target) return m;
            if(nums[l]<nums[m]){
                if(nums[l]<=target && nums[m]>=target)  r=m;	//图中情况1
                else l=m;
            }else if(nums[m]<nums[r]){
                if(nums[m]<=target && nums[r]>=target)  l=m;	//图中情况2
                else r=m;
            }
        }
        if(nums[l]==target) return l;
        if(nums[r]==target) return r;
        return -1;
    }
};
```

### 解法二

解法二说明

```c++

```

