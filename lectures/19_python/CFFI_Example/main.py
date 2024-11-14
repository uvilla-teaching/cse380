from cffi import FFI
import numpy as np

if __name__ == "__main__":
    header_name = "src/bessel.h"
    lib_name = "src/bessel.so"
    ffi = FFI()
    with open(header_name) as fid:
        ffi.cdef(fid.read())

    mylib = ffi.dlopen(lib_name)

    # Call a function with no arguments
    mylib.hello_cffi();

    # Call a function with a scalar (float) argument
    x = 1.
    y = mylib.bessel_j0(x)
    print("j0({0:1.4f}) = {1:1.4f}".format(x,y))

    # Pass numpy arrays
    n = 10
    x = np.random.uniform(size=n)
    y = np.zeros_like(x)
    
    x_ptr = ffi.cast("double *", x.ctypes.data)
    y_ptr = ffi.cast("double *", y.ctypes.data)
    
    mylib.vbessel_j0(x_ptr, y_ptr, x.size)

    [print("j0({0:1.4f}) = {1:1.4f}".format(x[i],y[i])) for i in range(n)]  
