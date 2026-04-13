# 🚀 LeetCode 2879: Display the First Three Rows

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)
![Topics](https://img.shields.io/badge/Topics-Pandas-purple)
![Acceptance](https://img.shields.io/badge/Acceptance-99.4%25-brightgreen)

---

## ⚡ The Problem

Select the first **3 rows** from a DataFrame and return them.

---

## 💡 The Solution (Pandas - Python)

```python
import pandas as pd

def selectFirstRows(employees):
    return employees.head(3)
```

### 🔥 How It Works

| Method | Description |
|--------|-------------|
| `.head(n)` | Returns first n rows |
| `.head()` | Default n = 5 |
| `.iloc[:3]` | Alternative using index |

**Time Complexity**: O(n)  
**Space Complexity**: O(n)

---

## 🎯 Alternative Methods

### Using iloc
```python
return employees.iloc[:3]
```

### Using slicing
```python
return employees[:3]
```

All produce the **same result**!

---

## 📊 Example

```python
data = {
    "name": ["Alice", "Bob", "Charlie", "David", "Eve", "Frank"],
    "department": ["Sales", "Engineering", "Marketing", "Sales", "HR", "Engineering"]
}
employees = pd.DataFrame(data)

print(selectFirstRows(employees))
```

**Output**:
```
     name  department
0   Alice       Sales
1     Bob  Engineering
2  Charlie  Marketing
```

---

## 🏆 Stats

| Metric | Value |
|--------|-------|
| Runtime | 52ms |
| Rank | Top 95% |

---

> *"First is always special - even in DataFrames!"* 👑