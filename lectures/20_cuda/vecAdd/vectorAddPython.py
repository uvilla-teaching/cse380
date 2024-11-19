import numpy as np
rng = np.random.default_rng(seed=42)

nums = 2**28
a_b = rng.uniform(0, 100, size=(nums,2))
a = a_b[:,0]
b = a_b[:,1]
c = np.zeros((nums,))

f = lambda x: np.exp(x)
for i in range(nums):
    for _ in range(50):
        c[i] += (f(a[i])+f(b[i]))
print(np.allclose(c, 50*(f(a)+f(b))))