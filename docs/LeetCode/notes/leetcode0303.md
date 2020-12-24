## [303. 区域和检索 - 数组不可变](https://leetcode-cn.com/problems/range-sum-query-immutable/)

难度简单

### 题目描述

给定一个整数数组  *nums*，求出数组从索引 *i* 到 *j* (*i* ≤ *j*) 范围内元素的总和，包含 *i, j* 两点。

**示例：**

```
给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
```

**说明:**

1. 你可以假设数组不可变。
2. 会多次调用 *sumRange* 方法。

### 分析

以O(n) 做一遍预处理，query时时间复杂度为O(1)

### 解法一

先算出从0到所有位置的和，查询时只需计算`res[j+1]-res[i]`即可

```c++
//执行用时 :32 ms, 在所有 C++ 提交中击败了81.98%的用户
//内存消耗 :19.1 MB, 在所有 C++ 提交中击败了6.61%的用户
class NumArray {
public:
    NumArray(vector<int>& nums) {
		if(nums.empty())	return;
        int cur = 0;
        res.push_back(0);	//res[i] = nums[0,i)
        for(int i = 0; i < nums.size(); i++) {
            cur += nums[i]; 
            //i=0时，加入到res中的为res[1],即res[1] = nums[0]
            res.push_back(cur);
        }             
    }
    
    int sumRange(int i, int j) {
        return res[j+1]-res[i]; 
        
    }
private:
    vector<int> res;
    //res[i]表示nums[0,i)的和
};
```

### 解法二

基本解法brute force，在每一次查询时均计算一次

```c++
class NumArray {
public:
    NumArray(vector<int>& nums) {
		nums_ = move(nums);
    }
    
    int sumRange(int i, int j) {
		int sum = 0;
        for(int k=i;k<=j;k++){
            sum += nums_[k];
        }
        return sum;
    }
private:
    vector<int> nums_;
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
```

