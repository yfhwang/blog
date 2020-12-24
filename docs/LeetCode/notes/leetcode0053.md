## [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)

### 题目描述

难度简单

给定一个整数数组 `nums` ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

**示例:**

```
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
```

**进阶:**

如果你已经实现复杂度为 O(*n*) 的解法，尝试使用更为精妙的分治法求解。

### 分析

题目分析

### 解法一

![屏幕快照 2020-02-21 22.07.09 (../images/屏幕快照 2020-02-21 22.07.09 (2).png)](../images/屏幕快照 2020-02-21 22.07.09 (2).png)

不用保存每次计算结果

```c++
//20ms, 15.4MB
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())    return 0;
        int curr = nums.front();
        int _max = curr;
        int size = nums.size();
        for(int i=1;i<size;i++) {
            curr = max(curr+nums[i],nums[i]);
            _max = max(_max,curr);
        }
        return _max;
    }
};
```

### 解法二

使用dp保存每次的结果

```c++
//8ms, 15.5MB
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())    return 0;
        int size=nums.size(); 
        vector<int> dp(size);
        dp[0]=nums[0];
        for(int i=1;i<size;i++){
            dp[i] = dp[i-1]>0? (dp[i-1]+nums[i]) : nums[i];
        }
        return *max_element(dp.begin(),dp.end());
    }
};
```

