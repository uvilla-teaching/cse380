# GDB session

First we need to compile using debug symbols

```
gcc -g -o hello hello.c
```

Then, we can start an interactive debugging session with

```
gdb ./hello
```

Inside GDB we can try this commands:

Run the program from start to end
```
run
```

Set a breakpoint, then run and check where am I

```
(gdb) break main
(gdb) run
(gdb) where
```

Set another breakpoint when entering the function `foo` and continue the exectution
```
(gdb) break foo
(gdb) c
(gdb) c
```

Show `list`

Delete breakpoints and add conditional breakpoint

```
(gdb) info br
(gdb) delete breakpoints 1 2
(gdb) break hello.c:16
(gdb) condition 3 i==401
(gdb) run
```

Show the value of of `i`

```
(gdb) print i
(gdb) where
```


