## [154. 寻找旋转排序数组中的最小值 II](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/)

### 题目描述

难度困难

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 `[0,1,2,4,5,6,7]` 可能变为 `[4,5,6,7,0,1,2]` )。

请找出其中最小的元素。

注意数组中可能存在重复的元素。

**示例 1：**

```
输入: [1,3,5]
输出: 1
```

**示例 2：**

```
输入: [2,2,2,0,1]
输出: 0
```

**说明：**

- 这道题是 [寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/description/) 的延伸题目。
- 允许重复会影响算法的时间复杂度吗？会如何影响，为什么？

### 分析

题目分析

### 解法一

模板改写，也可用于153题

```c++
//执行用时:8ms,在所有C++提交中击败了72.75%的用户
//内存消耗:14.5MB,在所有C++提交中击败了5.03%的用户
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
      	int m;
        while(l + 1 < r){
            m = l + (r - l) / 2;
            if(nums[m] < nums[r]) r = m;
            else if(nums[m] > nums[r]) l = m;
            else    r--;
        }
        if(nums[l]<=nums[r]) return nums[l];
        else return nums[r];
    }
};
```

### 解法二

DAQ 

和153题一样

```c++
// Author: Huahua
class Solution {
public:
    int findMin(vector<int> &num) {
        return findMin(num, 0, num.size()-1);
    }

private:
    int findMin(const vector<int>& num, int l, int r)
    {
        // One or two elements, solve it directly
        if (l+1 >= r) return	min(num[l], num[r]);
        
        // Sorted
        if (num[l] < num[r])	return num[l];
        
        int m = l + (r-l)/2;
        
        // Recursively find the solution
        return min(findMin(num, l, m - 1), 
                   findMin(num, m, r));
    }
};
```

