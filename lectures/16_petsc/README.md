## Compile

```
module load petsc
```

## Example runs

```
./solver -n 100
./solver -n 10 -mat_view
./solver -n 100 -ksp_view -ksp_monitor
./solver -n 100 -ksp_view -ksp_monitor -pc_type jacobi
./solver -n 100 -ksp_view -ksp_monitor -ksp_type cg -pc_type gamg
./solver -n 100 -log_view
```
