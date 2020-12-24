## [81. 搜索旋转排序数组 II](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/)

### 题目描述

难度中等

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 `[0,0,1,2,2,5,6]` 可能变为 `[2,5,6,0,0,1,2]` )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 `true`，否则返回 `false`。

**示例 1:**

```
输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true
```

**示例 2:**

```
输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false
```

**进阶:**

- 这是 [搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/) 的延伸题目，本题中的 `nums` 可能包含重复元素。
- 这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？

### 分析

- 区别：允许重复
- 问题，无法处理当l、m、r 相等时的情况

![屏幕快照 2020-02-24 17.47.57 (2)](../images/屏幕快照 2020-02-24 17.47.57 (2).png)

### 解法一

`else l++;`用来处理[l]==[m]的情况

```c++
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())    return false;
        int l=0,r=nums.size()-1;
        while(l+1<r){
            int m = l + (r-l)/2;
            if(nums[m]==target) return true;
            if(nums[l]<nums[m]){
                if(nums[l]<=target && target<=nums[m])  r=m;	
                else l=m;
            }else if(nums[l]>nums[m]){
                if(nums[m]<=target && target<=nums[r])  l=m;	
                else r=m;
            //IMPORTANT: Handle the worst case:1 1 1 1 0 1 1
            }else l++;
        }
        if(nums[l]==target || nums[r]==target) return true;
        return false;
    }
};
```

### 解法二

解法二说明

```c++

```

