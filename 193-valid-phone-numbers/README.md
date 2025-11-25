# 193 - Valid Phone Numbers

**Difficulty:** Easy

**Link:** [Valid Phone Numbers - LeetCode](https://leetcode.com/problems/valid-phone-numbers/)

## Problem Description

Given a text file `file.txt` that contains a list of phone numbers (one per line), write a one-liner bash script to print all valid phone numbers.

You may assume that a valid phone number must appear in one of the following two formats: (xxx) xxx-xxxx or xxx-xxx-xxxx. (x means a digit)

You may also assume each line in the text file must not contain leading or trailing white spaces.

## Example Test Cases

Assume that `file.txt` has the following content:
```
987-123-4567
123 456 7890
(123) 456-7890
```

Your script should output the following valid phone numbers:
```
987-123-4567
(123) 456-7890
```

## Solution Approach

### Algorithm Explanation

Use `awk` with regular expressions to match valid phone number patterns:

1. **Pattern 1:** `xxx-xxx-xxxx` - 3 digits, hyphen, 3 digits, hyphen, 4 digits
2. **Pattern 2:** `(xxx) xxx-xxxx` - 3 digits in parentheses, space, 3 digits, hyphen, 4 digits

### Step-by-Step Logic

1. Use `awk` to read each line of `file.txt`
2. Apply regex pattern: `/^[0-9]{3}-[0-9]{3}-[0-9]{4}$/ || /^\([0-9]{3}\) [0-9]{3}-[0-9]{4}$/`
3. Print lines that match either pattern

### Why It Works

- `awk` processes the file line by line
- The regex patterns explicitly match both valid formats
- The `||` operator ensures either pattern triggers a match

## Complexity Analysis

- **Time Complexity:** O(n) - Single pass through file
- **Space Complexity:** O(1) - No additional memory

## Accepted Solutions

| File Name | Language | Runtime | Memory |
|-----------|----------|---------|--------|
| 2025-11-25 10.05.14 - Accepted - runtime 68ms - memory 3.6MB.sh | Bash | 68ms | 3.6MB |
| 2025-11-25 10.05.44 - Accepted - runtime 80ms - memory 3.6MB.sh | Bash | 80ms | 3.6MB |
| 2025-11-25 10.07.14 - Accepted - runtime 73ms - memory 3.9MB.sh | Bash | 73ms | 3.9MB |

## Code Example (Best Solution - Bash)

```bash
# Read from the file file.txt and output all valid phone numbers to stdout.
awk '/^[0-9]{3}-[0-9]{3}-[0-9]{4}$/ || /^\([0-9]{3}\) [0-9]{3}-[0-9]{4}$/' file.txt
```

**Runtime:** 73ms | **Memory:** 3.9MB