# 🚀 LeetCode 121: Best Time to Buy and Sell Stock

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)
![Topics](https://img.shields.io/badge/Topics-Array-blue)
![Topics](https://img.shields.io/badge/Topics-Dynamic%20Programming-purple)
![Acceptance](https://img.shields.io/badge/Acceptance-53.8%25-yellow)

---

## ⚡ The Problem

Given an array `prices` where `prices[i]` is the stock price on day `i`.

Find the maximum profit you can achieve with **one transaction** (buy once, sell once).

- You must buy before selling
- If no profit possible, return 0

---

## 💡 The Solution (C++)

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices[i].size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            
            int profit = prices[i] - minPrice;
        
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }

        return maxProfit;
    }
};
```

### 🔥 How It Works (Kadane's Algorithm Variation)

1. Track **minimum price** seen so far
2. Calculate potential profit = current price - minPrice
3. Update **maximum profit** if better
4. Single pass through the array!

**Time Complexity**: O(n)  
**Space Complexity**: O(1)

---

## 🎯 Key Insight

| Day | Price | Min So Far | Profit |
|-----|-------|------------|--------|
| 0   | 7     | 7          | 0      |
| 1   | 1     | 1          | 0      |
| 2   | 5     | 1          | 4      |
| 3   | 3     | 1          | 2      |
| 4   | 6     | 1          | 5 ← max|

We find min price first, THEN calculate profits!

---

## 🏆 Stats

| Metric | Value |
|--------|-------|
| Runtime | 4ms |
| Memory | 13.4 MB |
| Rank | Top 95% |

---

> *"The stock market of algorithms: buy low, sell high."* 📈