Numpy random performance
========================

## 1 time an array of 500.000.000 numbers

    (cds-advanced-programming) MacBook-Air-van-Sander:ex0.2 sander$ time python3 random_numpy.py
    
    real    0m44.533s
    user    0m6.987s
    sys     0m2.541s
    
## 500 times an array of 1.000.000 numbers
    
    (cds-advanced-programming) MacBook-Air-van-Sander:ex0.2 sander$ time python3 random_numpy_many.py
    
    real    0m7.642s
    user    0m5.696s
    sys     0m0.506s

### It seems generating many arrays significantly increases the execution speed