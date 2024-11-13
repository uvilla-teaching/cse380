# Python

## Python at TACC

1. Do not use the system python; instead load the module

```
module load python3
```

It will come with some useful packages

```
python3 -c "import numpy; print(numpy.__version__)"
python3 -c "import scipy; print(scipy.__version__)"
python3 -c "import h5py; print(h5py.__version__)"
python3 -c "import mpi4py; print(mpi4py.__version__)"
```

2. Use virtual enviroments when needed more packages
