# Boost test

First load the boost module

```
module loab boost
```

Simply type make to compile.

To check the exist status run

```
./ex1.exe
echo $?
```

and similarly
```
./ex2.exe
echo $?
```

To list the content of a test
```
./ex2.exe --list_content
```

To run a specific test
```
./ex2.exe -t mysuite/test2
```

Rather verbose
```
./ex2.exe --help
```
