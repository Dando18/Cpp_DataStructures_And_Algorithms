### BUBBLE SORT ###
-------------------
Bubble sort is a simple sorting algorithm usually only implemented for its ease to code and for smaller lists. It works by repeatedly stepping through the list and comparing adjacent elements and swapping them if needed.


|           | Worst    | Best   | Average  | Worst-Space |
| --------- | -------- | ------ | -------- | ----------- |
| Insertion | _O_(n^2) | _O_(n) | _O_(n^2) | _O_(1)      |


_Ex:_ sorting this list `2 1 3 4`

```
    v       
    2 1 3 4  // we start off with 2 and compare it with every subsequent element
    v     v
    2 1 3 4  // 2 < 4 so no swap is made
    v   v 
    2 1 3 4  // 2 < 3 so no swap is made
    v v
    2 1 3 4  // 2 > 1 so we swap them
      v
    1 2 3 4  // now we compare 2 with 3 and 4 and so on... in this case, the list is sorted, so no more swaps will be made
```