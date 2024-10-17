Prepare an enviroment consistent with your container
```
module purge
module load gcc/11.2.0   mvapich2/2.3.7   tacc-apptainer/1.1.8
```


```
apptainer build tacc.sif docker://uvilla/step3:2024.1
ls -l
```

```
apptainer exec --cleanenv tacc.sif /bin/bash --login
```
Note to use `--login`

The current folder is already mounted
```
ls
ls /
```

Now run in parallel
```
MV2_SMP_USE_CMA=0 ibrun -n 16 apptainer run tacc.sif /hello_mpi
```


