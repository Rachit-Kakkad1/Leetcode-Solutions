# 🚀 LeetCode 204: Count Primes

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
![Topic: Math](https://img.shields.io/badge/Topic-Math-blue)
![Hash Table](https://img.shields.io/badge/Topic-Hash_Table-blue)
![Status: ✅ Solved](https://img.shields.io/badge/Status-Solved-brightgreen)

## 📋 Problem Statement

Given an integer `n`, return the number of prime numbers less than `n`.

---

## 📌 Quick Summary

| | |
|---|---|
| **Problem #** | 204 |
| **Difficulty** | Medium |
| **Topics** | Math, Hash Table |
| **Companies** | Amazon, Apple, Google |
| **Similar Problems** | [Ugly Number](./263-ugly-number) |

---

## 🎯 Example Test Cases

### ✅ Example 1:
```
Input: n = 10
Output: 4
Explanation: Primes less than 10 are: 2, 3, 5, 7
```

### ✅ Example 2:
```
Input: n = 0
Output: 0
```

### ✅ Example 3:
```
Input: n = 1
Output: 0
```

---

## ⚠️ Constraints

```
0 ≤ n ≤ 5 * 10^6
```

---

## 💡 Solution Approaches

### 🔹 Approach 1: Sieve of Eratosthenes (Optimal) ✅ RECOMMENDED

**Intuition:** Mark all multiples of each prime as non-prime.

| | |
|---|---|
| **Time** | O(n log log n) |
| **Space** | O(n) |
| **Runtime** | 154ms ✅ |

**Step-by-Step:**
1. Create a boolean array to mark primes
2. Starting from 2, mark all multiples as non-prime
3. Only need to iterate up to sqrt(n)
4. Count remaining primes

**Why it works:**
- Each prime p marks multiples starting from p*p
- Reduces to O(n log log n) complexity

---

## 📝 Detailed Implementation

### C ⭐
```c
int countPrimes(int n) {
    if (n <= 2) return 0;
    bool *isPrime = (bool *)malloc(n * sizeof(bool));
    for (int i = 2; i < n; i++) isPrime[i] = true;
    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i)
                isPrime[j] = false;
        }
    }
    int count = 0;
    for (int i = 2; i < n; i++)
        if (isPrime[i]) count++;
    free(isPrime);
    return count;
}
```

**Key Points:**
- Sieve of Eratosthenes algorithm
- O(n log log n) time
- Runtime: 154ms, Memory: 39.3MB

---

## 🎯 Complexity Analysis

| Approach | Time | Space | Status |
|----------|------|-------|--------|
| **Sieve of Eratosthenes** | **O(n log log n)** | **O(n)** | ✅ Accepted |
| Brute Force | O(n√n) | O(1) | ❌ TLE |

**Why O(n log log n)?**
- Classic Sieve complexity

**Why O(n) space?**
- Boolean array for marking

---

## 🔥 All Accepted Solutions

| File Name | Language | Runtime | Memory |
|----------|---------|---------|--------|
| 2025-11-10 17.05.22 - Accepted | **C** | **154ms 🟡** | **39.3MB** |
| 2025-11-10 17.09.55 - Accepted | Python 🐍 | 238ms 🟡 | 23.4MB |

---

## 🎓 Key Takeaways

### ✅ Best Practices
1. **Use Sieve** for prime counting
2. **Start from p*p** to avoid redundant work
3. **Optimize** with sqrt(n) loop

### ❌ Common Mistakes
1. Starting from 2 instead of p*p
2. Not handling n < 2 edge case
3. Using brute force (causes TLE)

### 💡 Follow-up Questions
- How to find nth prime?
- How to optimize space?

---

## 🔗 Related Problems

| # | Problem | Difficulty | Status |
|---|---------|-----------|--------|
| 263 | Ugly Number | Easy | 📝 |
| 507 | Perfect Number | Easy | 📝 |

---

## 📈 Success Metrics

![C](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=flat&logo=python&logoColor=white)

**Total Submissions:** 2️⃣ **Accepted:** 2️⃣ **Acceptance Rate:** 100% ✅

---

*Made with ❤️ | Last Updated: 2026-04-13*
