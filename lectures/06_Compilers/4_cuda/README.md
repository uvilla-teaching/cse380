# Compile a cuda program

Load the cuda module

```
module load cuda
which nvcc
```

Try to compile...
```
nvcc hello_cuda.cu -o hello_cuda
```
Specify the path for the header files
```
nvcc -I include hello_cuda.cu -o hello_cuda
```

Now we need a compute node with GPU support
```
idev -A CDA23007 -t 0:10:0 -p gpu-a100-small -n 1 -N 1
./hello_cuda
```
