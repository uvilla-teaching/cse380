# Compiler warnings are your friends

First let's compile with CGG without any special compiler warning flag

```
gcc -o problem problem.c
./problem
```

Now, let's turn on compiler warnings

```
gcc -o problem -Wall problem.c
```
