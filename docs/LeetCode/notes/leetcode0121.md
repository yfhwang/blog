## [121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)

### 题目描述

难度简单

给定一个数组，它的第 *i* 个元素是一支给定股票第 *i* 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

**示例 1:**

```
输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
```

**示例 2:**

```
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
```

### 分析

![123](../images/屏幕快照 2020-02-21 22.45.03 (2).png)



### 解法一

以价格数组来做状态转移

```c++
// Author: Huahua
// Runtime: 6 ms
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        if (n < 1) return 0;
        vector<int> min_prices(n);	//前i天（包括i）的最低价格
        vector<int> max_profit(n);	//第i天为止的最大收益
        min_prices[0] = prices[0];
        max_profit[0] = 0;
        for (int i = 1; i < n; ++i) {
            min_prices[i] = min(min_prices[i - 1], 
                                prices[i]);
            
            max_profit[i] = max(max_profit[i - 1], 
                                prices[i] - min_prices[i - 1]);
            //以前i-1天的最低价买进，以当天价卖出
        }
        return max_profit[n - 1];
    }
};
```

### 解法二

以收益来做状态转移

先根据价格计算出每天的收益gain数组（第0天收益为0）

将问题转化为：在gain数组中找出它的最大子数组

```c++
// Author: Huahua
// Runtime: 6 ms
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        vector<int> gains(n - 1, 0);
        for (int i = 1; i < n; ++i)
            gains[i - 1] = prices[i] - prices[i - 1];
        return max(0, maxSubArray(gains));
    }
private:
    // From LC 53. Maximum Subarray
    int maxSubArray(vector<int>& nums) {
        vector<int> f(nums.size());
        f[0] = nums[0];
        
        for (int i = 1; i < nums.size(); ++i)
            f[i] = max(f[i - 1] + nums[i], nums[i]);
        
        return *std::max_element(f.begin(), f.end());
    }
};
```

### 解法三

我的做法：不使用dp来保存，和解法一类似

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())	return 0;
        int n=prices.size();
        int profit=0,lowPriceDate=0,currProfit = 0;
        for(int i=1;i<n;i++){
            if(prices[i]<prices[lowPriceDate]){
                lowPriceDate=i;
            }else{
                currProfit = prices[i]-prices[lowPriceDate];
                if(currProfit>profit)
                    profit=currProfit;
            }

            //lowPriceDate=prices[i]<prices[lowPriceDate]? i:lowPriceDate;
            //profit=(prices[i]-prices[lowPriceDate]>profit)? prices[i]-prices[lowPriceDate]:profit;
        }
        return profit;
    }
};
```

