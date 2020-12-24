## [4. 寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)

### 题目描述

难度困难

给定两个大小为 m 和 n 的正序（从小到大）数组 `nums1` 和 `nums2`。

请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 `nums1` 和 `nums2` 不会同时为空。

**示例 1:**

```
nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
```

**示例 2:**

```
nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
```

### 分析

题目分析

### 解法一

解法一说明

```python
#sol1
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        i = 0
        j = 0
        nums3 = []
        while(i < len(nums1) and j < len(nums2)):
            if(nums1[i] < nums2[j]):
                nums3.append(nums1[i])
                i=i+1
            else:
                nums3.append(nums2[j])
                j=j+1
        while(i < len(nums1)):
            nums3.append(nums1[i])
            i=i+1
        while(j < len(nums2)):
            nums3.append(nums2[j])
            j=j+1
        if( len(nums3) % 2 == 1 ):
            return nums3[len(nums3)//2]/1.0
        else:
            return (nums3[len(nums3)//2]+nums3[len(nums3)//2-1]) / 2.0
```

### 解法二

解法二说明

```python
#sol2
import sys
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n1 = len(nums1)
        n2 = len(nums2)
        #总是在小的数组上进行二分搜索
        if(n1 > n2):
            return self.findMedianSortedArrays(nums2, nums1)
        
        k = (n1+n2+1) // 2 #第k个元素是左中位数
        
        l = 0
        r = n1
        
        while(l < r):
            m1 = l + (r - l) // 2
            m2 = k - m1
            if (nums1[m1] < nums2[m2-1]):
                l = m1 + 1
            else:
                r = m1
                
        m1 = l
        m2 = k - l
        
        #找到左中位数
        c1 = max(-sys.maxsize-1 if m1 <= 0 else nums1[m1-1],
                 -sys.maxsize-1 if m2 <= 0 else nums2[m2-1])
        
        if((n1+n2) % 2 == 1):
            return c1
        
        c2 = min(sys.maxsize if m1 >= n1 else nums1[m1],
                 sys.maxsize if m2 >= n2 else nums2[m2])

        return (c1 + c2) / 2
```

