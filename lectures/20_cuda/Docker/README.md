# Docker for CUDA

Two important notes:
1. You can create a Docker image for cuda on a machine that does not have any CUDA GPU.
2. It is tricky to use GPUs in Docker (it requires additional plug-ins), it works out of the box in Apptainer ;)

## Step 1: Build locally
Build the image locally and push to DockerHub

```
docker buildx build -t uvilla/cse380-cuda:latest .
docker push uvilla/cse380-cuda:latest
```

## Step 2: Deploy on TACC via apptainer
First request an GPU node
```
idev -t 1:00:00 -p gpu-a100-small -N 1 -n 1
```

Get the correct modules
```
module load tacc-apptainer/1.1.8 gcc/11.2.0 mvapich2/2.3.7 cuda/12.2
```

Pull the container
```
apptainer pull docker://uvilla/cse380-cuda:latest
```

Run with option `--nv`
```
export IMAGE=cse380-cuda_latest.sif
MV2_SMP_USE_CMA=0 apptainer exec --nv $IMAGE nvidia-smi
MV2_SMP_USE_CMA=0 apptainer exec --nv $IMAGE /bin/bash
```