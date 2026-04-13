# 🚀 LeetCode 2877: Create a DataFrame from List

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)
![Topics](https://img.shields.io/badge/Topics-Pandas-purple)
![Acceptance](https://img.shields.io/badge/Acceptance-97.5%25-brightgreen)

---

## ⚡ The Problem

Create a DataFrame from a 2D list `student_data` with columns:
- `student_id`
- `age`

Return the resulting DataFrame.

---

## 💡 The Solution (Pandas - Python)

```python
import pandas as pd

def createDataframe(student_data):
    df = pd.DataFrame(student_data, columns=["student_id", "age"])
    return df
```

### 🔥 How It Works

| Parameter | Description |
|-----------|-------------|
| `student_data` | 2D list (list of lists) |
| `columns` | Column names |

**Time Complexity**: O(n)  
**Space Complexity**: O(n)

---

## 📊 Example

```python
student_data = [[1, 15], [2, 14], [3, 16]]

df = createDataframe(student_data)
print(df)
```

**Output**:
```
   student_id  age
0           1   15
1           2   14
2           3   16
```

---

## 🎯 Alternative: From Dictionary

```python
def createDataframe(student_data):
    data = {
        "student_id": [row[0] for row in student_data],
        "age": [row[1] for row in student_data]
    }
    return pd.DataFrame(data)
```

---

## 🏆 Stats

| Metric | Value |
|--------|-------|
| Runtime | 56ms |
| Rank | Top 90% |

---

> *"Data from list, knowledge to miss!"* 📚