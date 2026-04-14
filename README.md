# Galach
Galach is simple brainf*ck-like language.

# Keywords:
G - memory pointer goes up.  
L - memory pointer goes down.  
A - Adds 1 to current cell.  
C - Subtracts 1 from current cell.  
H - Prints content of current cell.  
( - Start of do while loop.   
) - End of do while loop.

Do while loop's condition is stored in t[x] where x is index of left parentheses and t is token vector.
Loop stops when t[x] == 0

Galach does not support nested loops;
