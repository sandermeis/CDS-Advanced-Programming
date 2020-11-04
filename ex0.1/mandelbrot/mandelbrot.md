C++ versus Python performance
==============

### c++ executable

    (cds-advanced-programming) MacBook-Air-van-Sander:mandelbrot sander$ time (./mandelbrot args > mandelbrot.pbm )
    
    real    0m0.016s
    user    0m0.002s
    sys     0m0.004s

### Python code

    (cds-advanced-programming) MacBook-Air-van-Sander:mandelbrot sander$ time (python3 mandelbrot.py 1)
    P4
    1 1
    
    real    0m0.577s
    user    0m0.491s
    sys     0m0.255s

## Compiled code seems to be orders of magnitude faster