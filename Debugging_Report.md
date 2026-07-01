# Debugging Report

## Project Title
**To-Do List Management System (C++)**

---

## Bug Description

An intentional logical bug was introduced in the **Mark Task Complete** feature. The program marked the wrong task as completed because the vector index was accessed incorrectly.

### Buggy Code

```cpp
tasks[num].markComplete();
```

---

## Expected Result

When the user enters a task number, the selected task should be marked as completed.

### Example

Input:

```
1. Study OOP
2. Complete Assignment

Enter task number: 1
```

Expected Output:

```
1. Study OOP (Completed)
2. Complete Assignment
```

---

## Actual Result

Instead of marking the first task as completed, the second task was marked.

### Example

Input:

```
1. Study OOP
2. Complete Assignment

Enter task number: 1
```

Actual Output:

```
1. Study OOP
2. Complete Assignment (Completed)
```

---

## Root Cause

The program used:

```cpp
tasks[num]
```

The task number entered by the user starts from **1**, while vector indexing starts from **0**. Therefore, the code accessed the next task instead of the selected task.

---

## Debugging Steps

1. Ran the program successfully.
2. Added two tasks:
   - Study OOP
   - Complete Assignment
3. Selected **Mark Task Complete**.
4. Entered task number **1**.
5. Observed that the second task was marked as completed instead of the first.
6. Examined the `markComplete()` function.
7. Found that the program was using `tasks[num]`.
8. Realized the indexing error because vectors are zero-based.
9. Corrected the code to use `tasks[num - 1]`.
10. Ran the program again to verify the fix.

---

## Screenshots

Include the following screenshots in your repository:

- `before_bug.png` – Program working correctly before introducing the bug.
- `bug.png` – Incorrect output after introducing the bug.
- `fixed.png` – Correct output after fixing the bug.

---

## Final Fix

The incorrect indexing was replaced with the correct zero-based index.

### Correct Code

```cpp
tasks[num - 1].markComplete();
```

---

## Conclusion

The bug was caused by an off-by-one indexing error while accessing the vector of tasks. After correcting the index, the program correctly marks the selected task as completed. This debugging process demonstrates how logical errors can be identified, analyzed, and resolved through testing and code inspection.
