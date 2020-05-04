# HW7: Micro Optimization of String Conversion

To build, simply run: `gcc -O3 -std=c99 -march=native -o driver -Werror -Wall -Wextra -pedantic *.c`

To test, run: `./driver quotes.txt 1000`

All performance statistics are measured on a Macbook Pro 2017 on a 2.3 GHz Dual-Core Intel Core i5.


## Part 1: Naive implementation

My implementation of the `atoi()` function is ~150% faster than the standard library function.

|Standard `atoi()` | My implementation
| --- | ---
0.054168s | 0.008065s

From my research, the standard library `atoi()` uses another function, called `strtol()` for string conversion. I found the implementation of `strtol()` [here](https://github.com/gcc-mirror/gcc/blob/master/libiberty/strtol.c). Based on what I know about the workload, which consists of base-10 numbers, I eliminated the branches where they check for the number base in my naive implementation. I also eliminated a lot of branches that check if the number is in a permissible range, including negative values. Reducing branches _really_ helped me achieve a faster run time.  

## Part 2: Optimized implementation

I reduced the run time from my naive implementation of the `convert_all()` function in part 1 from **0.008065s** to **0.004246s**. Based on my observation that the workload, aka the quotes, consists of mostly 4-digit characters, I optimized for this common case by completely removing the `for` loop in the naive `atoi()` function for this specific case, and switched to standard list indexing.

Another optimization technique that I used is replacing multiplication operations with bitwise operations. Particularly, I replaced `x = x * 10` with `x = (x << 3) + (x << 1)` when extracting digits in base 10.
