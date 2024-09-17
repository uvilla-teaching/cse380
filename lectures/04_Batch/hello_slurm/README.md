Compile with

```
mpicc hello.c -o hello
```

Submit to the queue with
```
sbatch job.script 
```

Or run interactively using

```
srun -p development -N 2 -t 00:01:00  -A CDA23007 --pty /bin/bash –l
```

or the custom TACC wrapper

```
idev -t 0:30:00 -N 2 -n 2 -A CDA23007 -p development
```
