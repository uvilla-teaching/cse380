# Object files

Compile (but not link) hello.c

```
$ icc -c hello.c
```
Try to run, then fix permissions and rerun.

```
$ ./hello.o 
-bash: ./hello.o: cannot execute binary file
```

Let's try to learn more about the object file 
```
$ file hello.o
foo.o: ELF 64-bit LSB relocatable, x86-64, version 1 (SYSV), not stripped
```
Note: `ELF` = executable and linkable format

Linking step

```
$ icc -o hello hello.o
$ ./hello
```
