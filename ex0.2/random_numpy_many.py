import numpy as np

N = 500000000

epochs = 500

for i in range(epochs):
    x = np.random.rand(N // epochs)
