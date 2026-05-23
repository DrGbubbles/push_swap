# push_swap


# Plan ? 
- Phase 1: overall architecture - parsing input and populating stacks
- Phase 2: building each individual action
- Phase 3: building the algorithms
- Phase 4: building the bonus - checker
- Phase 5: looking at complexity testing

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
