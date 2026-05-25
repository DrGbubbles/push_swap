# push_swap

  ## Plan

| Phase | Focus Area | Key Concepts Covered | Status |
| :--- | :--- | :--- | :---: |
| **1** | parsing input | overall architecture - parsing input - populating stacks - handling input flags | 🟢 Done |
| **2** | sorting algorithms | Implementing each algorithm | 🟡 In Progress  |
| **3** | Testing | checking complexity with --bench / validating against the checker | To Do |
| **4** | Bonus | Creating our own checker program | To Do |
---

# Bubble sort:

- find max element
- Find next max element 
- Etc 
 - This can be done by pb then rotate ra, then exchange an and b if a>b(O(n) for each element). When b is full then pa until a is full.

## Bubble sort 2:
### Other option: using only list a
Compare top two of a if ordered then rotate if disordered swap- keep track of number of rotations. 

## merg-ish sort:
###For mostly ordered list:- merge sort
- Rotate and push any disorder to list b. (O(n+n1))
- Sort b progressively- insertion into a sorted list. 
- Insert into sorted list a.
