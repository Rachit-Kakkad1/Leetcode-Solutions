# 🚀 LeetCode 2878: Get the Size of a DataFrame

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)
![Topics](https://img.shields.io/badge/Topics-Pandas-purple)
![Acceptance](https://img.shields.io/badge/Acceptance-99.1%25-brightgreen)

---

## ⚡ The Problem

Get the size (number of rows and columns) of a DataFrame.

Return: `[number_of_rows, number_of_columns]`

---

## 💡 The Solution (Pandas - Python)

```python
import pandas as pd

def getDataframeSize(players):
    rows = len(players)
    cols = len(players.columns)
    return [rows, cols]
```

### 🔥 How It Works

| Method | Returns |
|--------|---------|
| `len(df)` | Number of rows |
| `len(df.columns)` | Number of columns |
| `df.shape` | Both as tuple (rows, cols) |

**Time Complexity**: O(1)  
**Space Complexity**: O(1)

---

## 🎯 Shorter Alternative

```python
def getDataframeSize(players):
    return list(players.shape)
```

The `.shape` attribute returns `(rows, cols)` as a tuple!

---

## 📊 Example

```python
data = {
    "player_name": ["Alice", "Bob", "Charlie"],
    "score": [100, 95, 98]
}
players = pd.DataFrame(data)

print(getDataframeSize(players))  # [3, 2]
```

---

## 🏆 Stats

| Metric | Value |
|--------|-------|
| Runtime | 48ms |
| Rank | Top 95% |

---

> *"Size matters - especially in DataFrames!"* 📐