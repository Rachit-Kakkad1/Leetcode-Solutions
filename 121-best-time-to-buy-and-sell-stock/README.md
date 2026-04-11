# 🚀 LeetCode 121: Best Time to Buy and Sell Stock

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Array](https://img.shields.io/badge/Topic-Array-blue)
![Dynamic Programming](https://img.shields.io/badge/Topic-Dynamic_Programming-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

You are given an array `prices` where `prices[i]` is the price of a given stock on the i-th day.

You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.

Return *the maximum profit you can achieve from this transaction*. If you cannot achieve any profit, return `0`.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 121 |
| **Difficulty** | Easy |
| **Topics** | Array, Dynamic Programming |
| **Companies** | Amazon, Google, Microsoft |
| **Similar Problems** | [Best Time to Buy and Sell Stock II](./122-best-time-to-buy-and-sell-stock-ii) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
```

### ✅ Example 2:
```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
```

---

## ⚠️ Constraints

- 1 ≤ prices.length ≤ 10⁵
- 0 ≤ prices[i] ≤ 10⁴

---

## 💡 Solution Approaches

### 🔹 Approach 1: Single Pass (Optimal) ✅ RECOMMENDED

**Intuition:** Track minimum price seen so far and maximum profit at each step.

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |
| **Runtime** | 0ms ✅ |

**Step-by-Step:**
1. Initialize minPrice = prices[0], maxProfit = 0
2. For each day i from 1 to n-1:
   - Update minPrice if current price is lower
   - Calculate profit = prices[i] - minPrice
   - Update maxProfit if profit is higher
3. Return maxProfit

**Why it works:**
- Single pass finds optimal buy/sell pair
- At each point, we know best buy price before current day

---

## 📝 Detailed Implementation

### C++ ⭐
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
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

**Key Points:**
- Single pass, O(n) time
- O(1) space
- Runtime: 0ms, Memory: 97.5MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Single Pass** | **O(n)** | **O(1)** | ✅ Accepted |
| Brute Force | O(n²) | O(1) | ❌ TLE |

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2026-04-11 14.38.13 - Accepted - runtime 0ms - memory 97.5MB.cpp | **C++** | **0ms 🟢** | **97.5MB** |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. Store minimum price seen so far
2. Calculate profit at each step
3. Update maximum profit

### ❌ Common Mistakes
1. Not handling decreasing prices
2. Buying after selling (not allowed)

---

## 📈 Success Metrics

![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)

**Total Submissions:** 1️⃣ **Accepted:** 1️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*