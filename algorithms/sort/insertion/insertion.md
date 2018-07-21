### INSERTION SORT ###
---------------------------

Insertion sort is an in-place memory swap sorting algorithm that runs in _o_(n^2) time. Insertion sort is similar to how one would sort a deck of cards. You pick on element and search for its proper place in the list.


|           | Worst    | Best   | Average  | Worst-Space |
| --------- | -------- | ------ | -------- | ----------- |
| Insertion | _O_(n^2) | _O_(n) | _O_(n^2) | _O_(n)      |

_Ex:_ sorting this list `6 5 3 1 8 7 2 4`

```
      v
    6 5 3 1 8 7 2 4  // first we look at 6 and find its place in the list
        v    
    5 6 3 1 8 7 2 4 
          v
    3 5 6 1 8 7 2 4  
            v
    1 3 5 6 8 7 2 4  // nothing before 8 is greater than 8 so it can't be moved
              v
    1 3 5 6 8 7 2 4
                v
    1 3 5 6 7 8 2 4
                  v
    1 2 3 5 6 7 8 4
                     v
    1 2 3 4 5 6 7 8
```