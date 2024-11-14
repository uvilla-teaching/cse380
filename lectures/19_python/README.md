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
python3 -c "import mpi4py; print(mpi4py.__version__)"
```

2. Run a parallel job using mpi4py and petsc4py

First we request a compute note (either using `idev` or `sbatch`)
```
idev -t 0:10:0 -p vm-small -n 2 -N 1
```
Then we can run our parallel job as
```
ibrun python3 hello_mpi.py
```

To access `petsc4py` simply do
```module load petsc```

Then we can run our parallel job as
```
ibrun python3 hello_petsc4py.py -view_sol
```

3. Use virtual enviroments when needed more packages

This command will create a new directory to contain all the scripts to use
the virtual environment as well as where to install the new python packages.

```
python3 -m venv class-env
```

Note if you want to have access to the current python packages do
```
python3 -m venv --system-site-packages class-env 
```

To activate the enviroment 
```
source class-env/bin/activate
```

Note that this will change your shell prompt to show the name of the virtual enviroment.
Note that the virtual enviroment is configure to give you access to the ls6 `mpi4py` but
that you'll have to reinstall other packages as usual using `pip`.

*Note* When running on TACC you may have to install some python packages from source, e.g.
```
pip install "numpy<2.0" --no-binary :all:
```

To deactivate the enviroment simply call `deactivate`

