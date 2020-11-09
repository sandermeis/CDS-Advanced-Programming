C++ versus Python performance
==============

### c++ executable

    (cds-advanced-programming) MacBook-Air-van-Sander:nbody sander$ time ./nbody 1000000
    -0.169075164
    -0.169086185
    
    real    0m1.026s
    user    0m1.010s
    sys     0m0.004s

### Python code

    (cds-advanced-programming) MacBook-Air-van-Sander:nbody sander$ time python3 nbody.py 1000000
    -0.169075164
    -0.169086185
    
    real    0m13.060s
    user    0m12.938s
    sys     0m0.044s

## Compiled code again much faster